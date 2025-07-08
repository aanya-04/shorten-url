// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>
// // #include <winsock2.h>
// // #include <windows.h>
// #include "httplib.h"
// #include "json_v3_10_5.hpp"

// using namespace std;
// using namespace httplib;
// using json = nlohmann::json; 


// unordered_map<string ,string> shortToLong;

// unsigned int generateHash(string longUrl)
// {
//     unsigned int hashValue =0;

//     for(int i=0;i<longUrl.size();i++)
//     {
//         hashValue = (hashValue<<5)+(hashValue^longUrl[i]);
        
//     }
//     return hashValue;
// }

// string getShortUrlFromHash(unsigned int hashValue){
//     char base62Arr[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
//     const int base =62;
//     string shortUrl = "";
    
//     do {
//         unsigned int index = (hashValue%base);
//         char c = base62Arr[index];
//         shortUrl.push_back(c);
//         hashValue /= base;

//     }while(hashValue >0);
//   reverse(shortUrl.begin(),shortUrl.end());

//   return shortUrl;
// }
// string shortenUrl(string longUrl)
// {
//     unsigned int hashValue = generateHash(longUrl);
//     // cout<<"the hashvalue is"<<hashValue<<endl;
//     //   string shortUrl = getShortUrlFromHash(hashValue);


//     string shortUrl =getShortUrlFromHash(hashValue);
//     // cout<<"the short url is"<<shortUrl<<endl;

//     shortToLong[shortUrl] = longUrl;
//     return shortUrl;
// }
// int main(int argc,char const *argv[])
// {
//     Server server;
//     server.Post("/shorten",[](const Request& req, Response& res)
//     {
//         string longUrl = req.get_param_value("longUrl");
//         string shortUrl = shortenUrl(longUrl);
        


//         shortToLong[shortUrl] = longUrl;
//          res.set_content("{\"shortUrl\":\"" + shortUrl + "\"}", "application/json");

//     });

//      server.Get(R"(/(\w+))", [&](const Request& req, Response& res)
//     {
//          string shortUrl = req.matches[1];
//          string response;
         

//          json jsonResponse;
//          if(shortToLong.find(shortUrl) != shortToLong.end() ){
//            jsonResponse["url"] = shortToLong[shortUrl];
//            jsonResponse["statusCode"] = 302;
//          }
//          else
//          {
//             jsonResponse["url"] = "";
//             jsonResponse["statusCode"] = 404;
//          }
//          res.set_content(jsonResponse.dump(),"application/json");
//     });
//     cout<<"Server listening on port 8080"<<endl;

//     server.listen("localhost",8080);

//        return 0;
// }



// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>
// // #include <winsock2.h>
// // #include <windows.h>
// #include "httplib.h"
// #include "json_v3_10_5.hpp"

// using namespace std;
// using namespace httplib;
// using json = nlohmann::json;

// unordered_map<string, string> shortToLong;

// unsigned int generateHash(string longUrl)
// {
//     unsigned int hashValue = 0;

//     for (int i = 0; i < longUrl.size(); i++)
//     {
//         hashValue = (hashValue << 5) + (hashValue ^ longUrl[i]);
//     }
//     return hashValue;
// }

// string getShortUrlFromHash(unsigned int hashValue)
// {
//     char base62Arr[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
//     const int base = 62;
//     string shortUrl = "";

//     do
//     {
//         unsigned int index = (hashValue % base);
//         char c = base62Arr[index];
//         shortUrl.push_back(c);
//         hashValue /= base;

//     } while (hashValue > 0);
//     reverse(shortUrl.begin(), shortUrl.end());

//     return shortUrl;
// }

// string shortenUrl(string longUrl)
// {
//     unsigned int hashValue = generateHash(longUrl);
//     // Comment out the prints so terminal isn't cluttered
//     // cout << "the hashvalue is" << hashValue << endl;

//     string shortUrl = getShortUrlFromHash(hashValue);
//     // cout << "the short url is" << shortUrl << endl;

//     shortToLong[shortUrl] = longUrl;
//     return shortUrl;
// }

// int main(int argc, char const *argv[])
// {
//     Server server;

//     // Function to add CORS headers
//     auto add_cors_headers = [](Response &res) {
//         res.set_header("Access-Control-Allow-Origin", "*");
//         res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
//         res.set_header("Access-Control-Allow-Headers", "Content-Type");
//     };

//     // Handle OPTIONS preflight requests (required for CORS)
//     server.Options(R"(/.*)", [](const Request &req, Response &res) {
//         res.set_header("Access-Control-Allow-Origin", "*");
//         res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
//         res.set_header("Access-Control-Allow-Headers", "Content-Type");
//         res.status = 204; // No Content
//     });

//     // POST /shorten to create short URL
//     server.Post("/shorten", [&](const Request &req, Response &res) {
//         string longUrl = req.get_param_value("longUrl");
//         string shortUrl = shortenUrl(longUrl);
//         shortToLong[shortUrl] = longUrl;

//         add_cors_headers(res);

//         json jsonResponse;
//         jsonResponse["shortUrl"] = shortUrl;

//         res.set_content(jsonResponse.dump(), "application/json");
//     });

//     // GET /<shortUrl> to get original URL
//     server.Get(R"(/(\w+))", [&](const Request &req, Response &res) {
//         string shortUrl = req.matches[1];
//         json jsonResponse;
//         if (shortToLong.find(shortUrl) != shortToLong.end())
//         {
//             jsonResponse["url"] = shortToLong[shortUrl];
//             jsonResponse["statusCode"] = 302;
//         }
//         else
//         {
//             jsonResponse["url"] = "";
//             jsonResponse["statusCode"] = 404;
//         }

//         add_cors_headers(res);

//         res.set_content(jsonResponse.dump(), "application/json");
//     });

//     cout << "Server listening on port 8080" << endl;

//     server.listen("localhost", 8080);

//     return 0;
// }





#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "httplib.h"
#include "json_v3_10_5.hpp"

using namespace std;
using namespace httplib;
using json = nlohmann::json;

unordered_map<string, string> shortToLong;

unsigned int generateHash(string longUrl)
{
    unsigned int hashValue = 0;

    for (int i = 0; i < longUrl.size(); i++)
    {
        hashValue = (hashValue << 5) + (hashValue ^ longUrl[i]);
    }
    return hashValue;
}

string getShortUrlFromHash(unsigned int hashValue)
{
    char base62Arr[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int base = 62;
    string shortUrl = "";

    do
    {
        unsigned int index = (hashValue % base);
        char c = base62Arr[index];
        shortUrl.push_back(c);
        hashValue /= base;

    } while (hashValue > 0);
    reverse(shortUrl.begin(), shortUrl.end());

    return shortUrl;
}

string shortenUrl(string longUrl)
{
    unsigned int hashValue = generateHash(longUrl);
    string shortUrl = getShortUrlFromHash(hashValue);

    shortToLong[shortUrl] = longUrl;
    return shortUrl;
}

int main(int argc, char const *argv[])
{
    Server server;

    // Function to add CORS headers
    auto add_cors_headers = [](Response &res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
    };

    // Handle OPTIONS preflight requests (required for CORS)
    server.Options(R"(/.*)", [&](const Request &req, Response &res) {
        add_cors_headers(res);
        res.status = 204; // No Content
    });

    // POST /shorten to create short URL
    server.Post("/shorten", [&](const Request &req, Response &res) {
        add_cors_headers(res);

        // Parse JSON body
        try {
            auto j = json::parse(req.body);
            if (!j.contains("url")) {
                res.status = 400;
                res.set_content(R"({"error":"Missing 'url' field"})", "application/json");
                return;
            }

            string longUrl = j["url"];
            string shortUrl = shortenUrl(longUrl);

            json jsonResponse;
            jsonResponse["shortUrl"] = shortUrl;
            res.set_content(jsonResponse.dump(), "application/json");
        } catch (const std::exception& e) {
            res.status = 400;
            res.set_content(R"({"error":"Invalid JSON"})", "application/json");
        }
    });

    // GET /<shortUrl> to get original URL
    server.Get(R"(/(\w+))", [&](const Request &req, Response &res) {
        add_cors_headers(res);

        string shortUrl = req.matches[1];
        json jsonResponse;
        if (shortToLong.find(shortUrl) != shortToLong.end())
        {
            jsonResponse["url"] = shortToLong[shortUrl];
            jsonResponse["statusCode"] = 302;
        }
        else
        {
            jsonResponse["url"] = "";
            jsonResponse["statusCode"] = 404;
        }
        res.set_content(jsonResponse.dump(), "application/json");
    });

    cout << "Server listening on port 8080" << endl;

    // Listen on all interfaces (important for Render deployment)
    server.listen("0.0.0.0", 8080);

    return 0;
}

