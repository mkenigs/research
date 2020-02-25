// This file is a part of the IncludeOS unikernel - www.includeos.org
//
// Copyright 2015 Oslo and Akershus University College of Applied Sciences
// and Alfred Bratterud
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <net/inet4>
#include <os>

constexpr int port{8080};

void Service::start(const std::string &) {
  using namespace std::string_literals;

  auto &server = net::Inet4::stack().tcp().bind(port);
  server.on_connect([](auto conn) {
    conn->on_read(1024, [conn](auto buf, size_t n) {
      auto response{
          "HTTP/1.1 200 OK\r\n"
          "Content-Type: text/html; charset=UTF-8\r\n\r\n"
          "<!DOCTYPE html><html><head><title>Hello from unikerneland!</title>"
          "</head>"
          "<body><h1>Hello, you UniKernel world!</h1></body></html>\r\n"s};
      conn->write(response);
      conn->close();
    });
  });
}
