#include "about.hh"
#include <fstream>
#include <sstream>


void blockAbout(crow::Crow<> &app) {
    CROW_ROUTE(app, "/about")
    .methods("GET"_method)
    ([](){
        std::string file_path = "static/about.html";
        std::ifstream file(file_path, std::ios::binary);
        if (!file.is_open())
            return crow::response(404);
        std::stringstream oss;
        oss << file.rdbuf();
        return crow::response(oss.str());
    });
}