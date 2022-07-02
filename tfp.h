#pragma once
#include "net.h"

//Request codes
#define HEL	    0
#define DOW	    1
#define UPL	    2
#define DAT	    3
#define ACK     4
#define ERR	    5
#define DEL	    6
#define LDI	    7

//Error codes
#define NOT_DEFINED				0
#define FILE_NOT_FOUND			1
#define ACCESS_VIOLATION		2
#define DISK_FULL				3
#define ILLEGAL_TFTP_OPERATION	4
#define UNKNOWN_PORT			5
#define FILE_ALREADY_EXIST		6
#define NO_SUCH_USER			7
#define DIRECTORY_NOT_FOUND		8		

#define DATALEN		512
#define BUFFLEN		(2+2+DATALEN)

int GetRequestData(char *buff, int len, int *opcode, char *filename, char *username);
void RemoveFile(int sock, char *buff, char *dir, char *name, int wr, struct sockaddr_in *addr, socklen_t alen);
void WriteFile(int sock, char *buff, char *dir, char *name, int wr, struct sockaddr_in *addr, socklen_t alen);
void SendFile(int sock, char *buff, char *dir, char *name, struct sockaddr_in *addr, socklen_t alen);
void SendDir(int sock, char *buff, char *dir, char *name, struct sockaddr_in *addr, socklen_t alen);
void SendError(int sock, char *buff, int error, char *msg, struct sockaddr_in* addr, socklen_t len);
void SendAck(int sock, char* buff, int num, struct sockaddr_in *addr, socklen_t len);
void SendHello(int sock, char *buff, char *path, struct sockaddr_in *addr, socklen_t len);
