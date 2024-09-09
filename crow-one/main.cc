
#include <crow.h>
#include <fstream>
#include <sstream> 
#include "./blockroute/about.hh"
#include "./blockroute/index.hh"


int main(int argc, char **argv) {

    crow::SimpleApp app; 
    app.loglevel(crow::LogLevel::Debug);

    CROW_ROUTE(app, "/<path>")
    .methods("GET"_method)
    ([&](const std::string& path){
        std::string file_path = "static/"+path;
        std::cout << "file_path " << file_path;
        if (path.empty() || path.back() == '/'){
            file_path += "index.html";
        }else {file_path +=".html";}
        std::ifstream file(file_path);
        if (!file.is_open())
            return crow::response(404);
        std::stringstream buffer;
        buffer << file.rdbuf();
        return crow::response(buffer.str());
    });

    blockindex(app);
    blockAbout(app);

    app.port(12030).multithreaded().run();
}