#pragma once

#ifndef LANCLIENT
#define LANCLIENT

struct connectedClient
{
	connectedClient()
	{
		Sock = INVALID_SOCKET;
		Index = 0;

		sendFlag = 0;
		disconnectFlag = 0;
		sendCount = 0;
		iocpCount = 0;
	}

	SOCKET  Sock;
	unsigned __int64 Index;

	// IOCP �۾� ���� ������

	LONG sendFlag;				// send ���� �� üũ.
	LONG afterSendingDisconnect;
	LONG disconnectFlag;		// disconnect üũ

	LONG sendCount;						// ������ ��Ŷ�� ����
	LONG iocpCount;

	winBuffer recvQ;
	lockFreeQueue<Sbuf*> sendQ;
	OVERLAPPED recvOver, sendOver;
};

class LanClient
{

private:
	SOCKADDR_IN server;
	connectedClient *user;

	HANDLE hcp;	// IOCP HANDLE
	HANDLE *threadArr;

protected:
	char ip[16];
	IN_ADDR addr;
	short port;
	bool nagleOpt;
	unsigned int workerCount;
	bool connectFlag;

private:
	volatile LONG sendTPS;
	volatile LONG recvTPS;

private:

	static unsigned __stdcall connectThread(LPVOID _data);
	static unsigned __stdcall workerThread(LPVOID _data);
	static unsigned __stdcall tpsThread(LPVOID _data);

private:
	void recvPost(connectedClient *_ss);
	void sendPost(connectedClient *_ss);
	void completeRecv(LONG _trnas, connectedClient *_ss);
	void completeSend(LONG _trnas, connectedClient *_ss);

	void clientShutdown();
	void disconnect();
	void disconnect(SOCKET _sock);

protected:
	bool quit;
	int connectTotal;
	int psendTPS;
	int precvTPS;

protected:



protected:
	bool	Start(char *_ip, unsigned short _port, unsigned short _workerCount, bool _nagleOpt);
	bool	Stop(void);					
	void	SendPacket(Sbuf *_buf);

	void setTPS(void);

	virtual void OnClientJoin(void) = 0;
	virtual void OnClientLeave(void) = 0;
	virtual void OnRecv(Sbuf *_buf) = 0;

	virtual void OnError(int _errorCode, WCHAR *_string) = 0;

	virtual void OnTPS() = 0;

public:
	int getSendTPS(void);
	int getRecvTPS(void);
};

#endif // !LANCLIENT



