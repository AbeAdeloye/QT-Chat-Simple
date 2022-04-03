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
    Nick,
    Undefined
};
}

namespace ErrorType {
enum ErrorType{
    Undefined,
    DisconectedUser,
    RepeatedUser,        
};
}


#endif // NAMESPACES_H
