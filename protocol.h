#pragma once

// 2018.03.20  �α��μ��� -> ���Ӽ��� ��Ŷ ���� ����
//   - character object id ���� �߰�

// 2018.03.23 ���Ӽ��� �������� �߰�

// 2018.03.28 ĳ���� ���� & ���� �������� �߰�

// 2018.09.17	Ŭ���̾�Ʈ �α��� & ĳ���� ���� ���� �������� �и�
//					��Ŷ Ÿ�� �ڷ��� ���� : unsigned short	->	short
//					��û ��� �ڷ��� ���� : unsigned char		->	char
//					ĳ���� ���� ��Ŷ������ ���� : mongoDB object id -> index

// 2018.09.18	ĳ���� ���� ��Ŷ ���� : Index & character object id �߰�
//					ĳ���� ���� �� ���� ��Ŷ ���� : character object id �߰� & charArr ���� ����

// 2018.10.28  ȸ������, ȸ��Ż��, ����, �̵�ó�� �� ���� ����

enum protocol
{
	// �α��μ���
	loginProtocol = 100,

	// ���� ȸ������
	// short		Type
	// char		id[10]
	// char		pass[15]
	login_signUp_req,

	// ���� ȸ������ ����
	// short		Type
	// char		Result
	login_signUp_res,

	// ���� ȸ��Ż��
	// short		Type
	// char		id[10]
	// char		pass[15]
	login_withDrawal_req,

	// ���� ȸ��Ż�� ����
	// short		Type
	// char		Result
	login_withDrawal_res,

	// ���� �α��� ��û
	// short		Type
	// char		id[10]
	// char		pass[15]
	login_Login_req,

	// ���� �α��� ����
	// short		Type
	// char		Result			
	login_Login_res,

	// �׽�Ʈ ���� �α��� ��û
	// short		Type
	// char		id[10]
	// char		pass[15]
	login_test_Login_req,

	// ���� ĳ���� ���� �䫊
	// short		Type
	// short		charType
	// WCHAR	nickName[10]
	login_createChar_req,

	// ĳ���� ���� ����
	// short		Type
	// char		Result
	login_createChar_res,

	// ���� ĳ���� ���� ��û
	// short Type
	// char  charIndex
	// char[25]	objectId
	login_deleteChar_req,

	// ĳ���� ���� ����
	// short		Type
	// char		Result
	login_deleteChar_res,

	// ������ ĳ���� ���� ��û
	// short	Type
	login_charList_req,

	// ���� ĳ���� ���� ����
	// short		Type
	// char		Result
	// charArr	Data
	login_charList_res,

	// ������ ĳ���� ���� 
	// short		Type
	// char		charIndex
	login_userSelect_req,

	// �׽�Ʈ ���� ĳ���� ����
	// short		Type
	// int			testOID
	login_testSelect_req,

	// ���� ĳ���� ���� ���
	// short		Type
	//	char		Result
	login_userSelect_res,



	// �α��μ����� Ŭ���̾�Ʈ(����)���� ���Ӽ����� ä�ü����� �ּҸ� ������.

	// unsigned __int64		sessionKey
	// char	                    gameIp[16]
	// short		                gamePort
	login_userGameConnect_res,




	// login & server connection and authentication protocol


	// ����/ä�ü��� �α��� ��û
	// short		Type
	// char		serverNumber
	// char		serverType
	// char		ip[16]
	// short		port
	login_serverLogin_req,

	// ����/ä�ü��� �α��� ����
	// short		Type
	// char		Result
	login_serverLogin_res,

	// ����/ä�ü����� ĳ���� ���� �˸�
	// short						Type
	// unsigned __int64		sessionKey
	// char						charOid[25]
	//	unsigned __int64		accountNo
login_userAuth_req,

// ����/ä�ü��� ĳ���� ���� �˸� ����
// short		Type
// char		serverType			: ���Ӽ���, ä�ü��� ���� Ÿ��
// unsigned __int64 sessionKey
login_userAuth_res,





gameProtocol = 200,

// Ŭ���̾�Ʈ(����)�� ���Ӽ����� ���� �õ�
// unsigned short		Type;
// unsigned __int64 sessionKey;
// int		version;			// Ŭ���̾�Ʈ ����
game_loginUser_req,

// Virutal Client�� ���Ӽ����� ���� �õ�
// unsigned short		Type;
// unsigned __int64 sessionKey;
// int		version;			// Ŭ���̾�Ʈ ����
// int		characterOID
game_loginTestUser_req,

// ���Ӽ����� Ŭ���̾�Ʈ(����)���� ���� �õ� ��� ����
// unsigned short		Type;
// unsigned char		Result;
// unsigned __int64		Index;
game_loginUser_res,

// Ŭ���̾�Ʈ(����)�� �̵���û ����
// unsigned short	Type;
// unsigned __int64 Index;
// float	xDir;
// float	zDir;
// float	xForward;
// float	zForward;
// float	xPos;
// float	zPos;
game_move_req,

// ������ Ŭ���̾�Ʈ(����)���� �̵� ��Ŷ ����
// unsigned short	Type;
// unsigned __int64	Index;
// float					xDir;
// float					zDir
// float					xForward;
// float					zForward;
game_move_res,

// Ŭ���̾�Ʈ(����)�� ������û ����
// unsigned short	Type;
// unsigned __int64 Index;
// float					xForward;
// float					zForward;
// float					xPos;
// float					zPos
game_stop_req,

// ������ Ŭ���̾�Ʈ(����)���� ���� ��Ŷ ����
// unsigned short		Type;
// unsigned __int64		Index;
// float					xForward;
// float					zForward;
// float					xPos;
// float					zPos
game_stop_res,

// ������ Ŭ���̾�Ʈ ��ġ ����ȭ
// unsigned short	Type;
// unsigned __int64	Index;
// float					xPos;
// float					yPos;
// float					xForward;
// float					zForward;

game_sync_res,

// ������ Ŭ���̾�Ʈ(����) ���� ��Ŷ ���� (����)
// unsigned short			Type;
// unsigned __int64			Index;
// unsigned char			charType;
// WCHAR						nickName[NICKNAME_SIZE]
// float							xPos
// float							zPos
// float							xForward
// float							zForward
//	int								Level
// int								maxHP
// int								currentHP
game_newChar_res, game_newUser_res,

// ������ Ŭ���̾�Ʈ(����) ���� ��Ŷ ����
// unsigned short			Type;
// unsigned __int64		Index;
game_deleteUser_res,

// ������ Ŭ���̾�Ʈ(����) ���� ��Ŷ ����
// unsigned short			Type;
// unsigned __int64		Index;
game_deathUser_res,

// Ŭ���̾�Ʈ(����)�� ���� ��Ŷ ����
// unsigned short	Type
// unsigned __int64	Index
// float					xRotation
// float					zRotation
game_attack_req,

// ������ Ŭ���̾�Ʈ(����) ���� ��Ŷ ����
// unsigned short   Type
// unsigned __int64 Index
// float					xRotation
// float                  zRotation
game_attack_res,


// Ŭ���̾�Ʈ�� �������� Ÿ�� ��Ŷ ����
// unsigned short Type
// unsigned __int64 Index
// unsigned __int64 targetIndex
// float                    xPosition
// float                    zPosition
// int                      damage
game_hit_req,

// ������ Ŭ���̾�Ʈ���� Ÿ�� ��Ŷ ����
// unsigned short   Type
// unsigned __int64 damagerIndex
// float                    xPosition
// float                    zPosition
// int                      damage
// int                      damagerHP;
game_hit_res,

// ������ Ŭ���̾�Ʈ���� �ڵ� ȸ�� ��Ŷ ����
//	unsigned short	Type
// unsigned __int64	Index
//	int						recoveryAmount
// int						currentHP
game_Recovery_res,

// ���Ӽ����� �α��μ������� �÷��̾� �α׾ƿ��� �˸� (login status ����)
// short Type;
// unsigned __int64 accountNo;
// char		oid[25]
// int			Level
// char	nickName[20]
game_userLogout_req,
};

enum login_Result {
	Failed = 0,
	Overalpped,
	Success,
	accountSuspension,
};

enum login_serverType {
	GAME = 0,
	CHAT,
};

// Game
enum moveDirection
{
	Top, Down, Left, Right,
	TL, TR, DL, DR, None
};

enum playerStatus
{
	NONE, MOVE, ATTACK,
};

enum Game_Login_Result
{
	GAME_Failed = 0,
	GAME_versionMiss,
	GAME_SUCCESS,
};

enum EDHServerType
{
	gameServer = 0, chatServer,
};