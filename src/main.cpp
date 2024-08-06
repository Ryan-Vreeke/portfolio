#include <iostream>
#include <memory>
#include <webserve.h>

std::unique_ptr<webserve> web;
int main (int argc, char *argv[]) {
  web = std::make_unique<webserve>("./public", 8000);

  web->GET("/", [](WebContext ctx) -> std::string{
    return ctx.Render(200, "index");
  });

  web->POST("/home", [](WebContext ctx) -> std::string{
    return ctx.Render(200, "home");
  });

  web->POST("/projects", [](WebContext ctx) -> std::string{
    std::map<std::string, std::string> var{
      {".ProjName", "Templar"}
    };
    return ctx.Render(200, "projects", var);
  });

  web->POST("/work", [](WebContext ctx) -> std::string{
    return ctx.Render(200, "work");
  });

  web->start();
  return 0;
}
