#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve("example.com", "80");

        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        std::string request = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
        boost::asio::write(socket, boost::asio::buffer(request));

        std::array<char, 1024> response;
        boost::system::error_code error;
        while (size_t len = socket.read_some(boost::asio::buffer(response), error)) {
            std::cout.write(response.data(), len);
        }

        if (error != boost::asio::error::eof) {
            throw boost::system::system_error(error);
        }
    } catch (std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
