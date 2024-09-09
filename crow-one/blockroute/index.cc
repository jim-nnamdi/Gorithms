#include "index.hh"
#include <fstream>
#include <sstream>

void blockindex(crow::Crow<> &app){
    CROW_ROUTE(app, "/index")
    .methods("GET"_method)
    ([](){
        std::string file_path = "static/index.html";
        std::ifstream file(file_path, std::ios::binary);
        if (!file.is_open())
            return crow::response(404);
        std::stringstream oss;
        oss << file.rdbuf();
        return crow::response(oss.str());
    });
}