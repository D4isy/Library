#pragma once

#define Virtual_maxWSABUF 100

struct netHeader
{
	BYTE code;					// ���� �ڵ�
	WORD len;					// ��Ŷ�� ���� (��� ����)
	BYTE randCode;		// XOR code
	BYTE checkSum;		// checkSum
};

class Session
{
	friend class VirtualClient;

private:
	SOCKET Sock;

	SOCKADDR Addr;

	LONG recvFlag;
	LONG sendFlag;
	LONG lockFlag;
	LONG disconnectFlag;

	LONG sendCount;
	LONG disconnectAfterSend;
	LONG calledPQCSSend;

	winBuffer recvQ;
	lockFreeQueue<Sbuf*> *sendQ;

	OVERLAPPED recvOver, sendOver;

protected:
	int Index;

public:
	Session(void);
	~Session(void);

	void setAddr(SOCKADDR _addr);
	void sessionShutdown(void);
};

class VirtualClient
{
private:
	bool nagleOpt;
	tcp_keepalive keepaliveOpt;

	BYTE Code, Key1, Key2;

	unsigned int maxClient;
	unsigned int workerThreadCount;
	
	HANDLE hcp;
	HANDLE *workerThreadArray;
	
	bool configSettingFlag;
	bool clientShutdownFlag;

	unsigned int connectTPS;
	unsigned int sendTPS;
	unsigned int recvTPS;

	lockFreeQueue<int> *indexQueue;
	Session* sessionArray;

protected:
	unsigned int connectedClientCount;

	unsigned int totalConnected;
	unsigned int failedConnected;

	unsigned int pConnectTPS;
	unsigned int pSendTPS;
	unsigned int pRecvTPS;

private:

	static unsigned __stdcall connectThread(LPVOID _data);
	static unsigned __stdcall workerThread(LPVOID _data);

	void recvPost(Session *_ss);
	void sendPost(Session *_ss);
	void completedRecv(LONG _trans, Session *_ss);
	void completedSend(LONG _trans, Session *_ss);		

	void sessionShutdown(Session *_ss);			// ���ǰ� ������ ������ ����
	void disconnect(Session *_ss);						// ���� ���� ���� �� ó��
	void disconnect(SOCKET _sock);					// ���� ���� ���� (���� �Ҵ� ��)

	Session* acquireLockedSession(int _index);		// ���ǿ� ���� �ɰ�, ���� ������ ��ȯ
	void releaseLockedSession(Session *_ss);				// ������ ���� ����

	void checkAllClientDisconnect(void);

protected:
	void setTPS(void);		// 1�ʸ��� ����͸� ���� ���� (recvTPS -> pRecvTPS)

public:
	VirtualClient(void);
	~VirtualClient(void) {};

	bool setConfigData(unsigned int _maxClientCount, unsigned int _workerThreadCount, bool _nagleOpt);
	
	bool Start(void);
	bool Stop(void);

	void sendPacket(int _index, Sbuf *_buf, bool disconnectAfterSend = false);
	void clientShutdown(int _index);

	virtual void printSettingData()=0;

	virtual void OnConnect(int _index)=0;
	virtual void OnDisconnect(int _index)=0;
	virtual void OnRecv(int _index, Sbuf *_buf)=0;
	virtual void OnSend()=0;
};