/*
 * prog3_server.h
 *
 *  Created on: Feb 26, 2017
 *      Author: loehrj
 */

#ifndef PROG3_SERVER_H_
#define PROG3_SERVER_H_

#define MIN_PORT 1024
#define QLEN 6
#define NO_FLAGS 0

#define SUCCESS 1
#define FAILURE 0
#define INVALID -1

#define PARTICIPANT 1
#define MAX_PARTICIPANTS 255
#define OBSERVER 2
#define MAX_OBSERVERS 255
#define PENDING_PARTICIPANT 3
#define PENDING_OBSERVER 4
#define MAX_PENDING 255

#define USERNAME_MAX_LENGTH 10
#define MSG_MAX_LEN 1000
#define QUEUE_MAX 255

#include <sys/socket.h>

typedef struct Connection Connection;
struct Connection {
	int type;
	int sd;

	int name_len;
	char name[USERNAME_MAX_LENGTH+1];

	Connection *affiliated;

	int queue_len;
	char **msg_queue;

	int deferred_disconnect;
};

typedef struct ServerState {
	int p_listener;
	int o_listener;

	int p_count;
	int o_count;
	int pending_count;

	Connection **p_conns;
	Connection **o_conns;
	Connection **pending_conns;

	int fd_max;
	fd_set master_set;
	fd_set read_set;
	fd_set write_set;
	struct timeval timeout;

} ServerState;

int recv_(Connection *conn, void *buf, size_t len, int flags, ServerState *state);
int remove_connection(Connection *conn, ServerState *state);

void init_server_state(ServerState *state);
int init_listener(int port);
int negotiate_connection(int l_sd, ServerState *state);
int new_connection(int l_sd, ServerState *state);
int validate_username(char *name, int name_len, int type, ServerState *state);
int enqueue_message(char *msg, ServerState *state);
int main_server(int argc, char **argv);


extern int (*mock_accept)(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int mock_accept_success(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

#endif /* PROG3_SERVER_H_ */
