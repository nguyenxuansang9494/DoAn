#include <DatabaseConnectionFailedException.h>

DatabaseConnectionFailedException::DatabaseConnectionFailedException(string message) {
    this->message = message;
}

DatabaseConnectionFailedException::~DatabaseConnectionFailedException() {
}

