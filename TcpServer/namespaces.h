#ifndef NAMESPACES_H
#define NAMESPACES_H

namespace ConnectedState {
enum ConnectedState {
    WaitingGreeting,
    ReadingGreeting,
    ReadyForUse
};
}

namespace DataType {
enum DataType {
    Message,
    Ping,
    Pong,
    Greeting,
    Error,
    Undefined
};
}

namespace ErrorType {
enum ErrorType{
    DisconectedUser,
    RepeatedUser,
    Undefined
};
}


#endif // NAMESPACES_H
