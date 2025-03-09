#include <stdio.h>
#include <string.h>
#include "server.h"
#include "count.h"

int main(int argc, char* argv[]) {
    Server server = create_server(5531);
    while (1) {
        Request request = next_request(&server);
        switch(request.method) {
            case GET:
                char* message = "HTTP/1.1 200 OK\r\n";
            respond(&server, &request, 200, message);
            break;
            case POST:
                if(strcmp(request.path, "/count") == 0) {
                    count(server, request);
                }

            break;
            default:

                fprintf(stderr, "request method not understood");
        }
    }
    return 0;
}