#ifndef RIDEREQUEST_H
#define RIDEREQUEST_H

struct RideRequest {
    int requestId;
    int userId;
    int pickupNode;
    int dropNode;
};

#endif