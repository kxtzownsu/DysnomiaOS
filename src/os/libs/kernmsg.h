// kernmsg.h

#ifndef KERNMSG_H
#define KERNMSG_H

#define MAX_MESSAGES 100
#define MAX_MESSAGE_LENGTH 256

struct MessageBuffer {
    char messages[MAX_MESSAGES][MAX_MESSAGE_LENGTH];
    int messageCount;
};

void initMessageBuffer(struct MessageBuffer *buffer);
void addMessage(struct MessageBuffer *buffer, const char *title, const char *message, const char *type);
void displayMessages(struct MessageBuffer *buffer);
void kernmsg(struct MessageBuffer *buffer, const char *type, const char *title, const char *message);
#endif // KERNMSG_H
