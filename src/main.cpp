#include <iostream>
#include <memory>
#include <webserve.h>

std::unique_ptr<webserve> web;
int main (int argc, char *argv[]) {
  web = std::make_unique<webserve>("./public", 8000);

  web->GET("/", [](WebContext ctx) -> std::string{
    return ctx.Render(200, "index");
  });

  web->GET("/home", [](WebContext ctx) -> std::string{
    return ctx.Render(200, "home");
  });

  web->start();
  return 0;
}
