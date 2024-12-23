#include <iostream>
#include <boost/asio.hpp>
#include <boost/beast.hpp>

namespace asio = boost::asio;
namespace beast = boost::beast;
namespace http = beast::http;
using tcp = asio::ip::tcp;

void handle_request(http::request<http::string_body> req, http::response<http::string_body>& res) {
    // Handle WebRTC signaling messages here
    res.result(http::status::ok);
    res.set(http::field::server, "WebRTC Server");
    res.set(http::field::content_type, "text/plain");
    res.body() = "Hello, WebRTC!";
    res.prepare_payload();
}

void session(tcp::socket socket) {
    beast::flat_buffer buffer;
    http::request<http::string_body> req;
    http::read(socket, buffer, req);
    http::response<http::string_body> res;
    handle_request(req, res);
    http::write(socket, res);
}

int main() {
    try {
        asio::io_context ioc;
        tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), 8080));
        for (;;) {
            tcp::socket socket(ioc);
            acceptor.accept(socket);
            std::thread(session, std::move(socket)).detach();
        }
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
