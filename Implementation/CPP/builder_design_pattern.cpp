#include <iostream>
#include <map>
#include <string>
using namespace std;

class HttpRequest {
    string url;
    map<string, string> headers;
    string body;
    string timeout;

    // Private constructor
    HttpRequest() {}

public:
    friend class HttpRequestBuilder;

    void execute() {
        cout << "Http Request execution starts:\n";

        cout << "URL: " << url << endl;

        if (!headers.empty()) {
            cout << "Headers:\n";
            for (auto &h : headers) {
                cout << "  " << h.first << " : " << h.second << endl;
            }
        }

        if (!body.empty()) {
            cout << "Body: " << body << endl;
        }

        if (!timeout.empty()) {
            cout << "Timeout: " << timeout << endl;
        }
    }
};

class HttpRequestBuilder {
    HttpRequest* httpRequest;

public:
    HttpRequestBuilder() {
        httpRequest = new HttpRequest();
    }

    HttpRequestBuilder& withUrl(const string& url) {
        httpRequest->url = url;
        return *this;
    }

    HttpRequestBuilder& withHeaders(const string& key, const string& value) {
        httpRequest->headers[key] = value;
        return *this;
    }

    HttpRequestBuilder& withBody(const string& body) {
        httpRequest->body = body;
        return *this;
    }

    HttpRequestBuilder& withTimeout(const string& timeout) {
        httpRequest->timeout = timeout;
        return *this;
    }

    HttpRequest* build() {
        if (httpRequest->url.empty()) {
            throw runtime_error("Please specify URL");
        }
        return httpRequest;
    }
};

int main() {
    HttpRequestBuilder builder;

    HttpRequest* request = builder
        .withUrl("www.example.com")
        .withBody("this example body")
        .withHeaders("Content-Type", "application/json")
        .withTimeout("5s")
        .build();

    request->execute();

    delete request; // cleanup
    return 0;
}
