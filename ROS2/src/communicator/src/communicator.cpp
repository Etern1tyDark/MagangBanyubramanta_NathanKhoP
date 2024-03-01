#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <asio.hpp>

#include "rclcpp/rclcpp.hpp"
#include "obj_msg/msg/motion.hpp"

using namespace asio;
using asio::serial_port_base;

using namespace std::chrono_literals;
using std::placeholders::_1;

class Communicator : public rclcpp::Node
{
public:
    Communicator() : Node("communicator")
    {   
        port.set_option(serial_port_base::baud_rate(115200));
        port.set_option(serial_port_base::flow_control(serial_port_base::flow_control::software));
        port.set_option(serial_port_base::parity(serial_port_base::parity::none));
        port.set_option(serial_port_base::stop_bits(serial_port_base::stop_bits::one));
        port.set_option(serial_port_base::character_size(8));

        subscriber_ = this->create_subscription<obj_msg::msg::Motion>("commands", 10, std::bind(&Communicator::topic_callback, this, _1));
    }

private:
    void topic_callback(const obj_msg::msg::Motion &message) {
        uint8_t send[5];
        
        send[0] = message.x_cmd;
        send[1] = message.y_cmd;
        send[2] = message.yaw;
        send[3] = message.depth;

        RCLCPP_INFO(this->get_logger(), "Sending, x = [%d], y = [%d], a = [%d], z = [%d]", message.x_cmd, message.y_cmd, message.yaw, message.depth);
        asio::write(port, asio::buffer(send, sizeof(send)));
    }

    io_service io;
    serial_port port;
    rclcpp::Subscription<obj_msg::msg::Motion>::SharedPtr subscriber_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Communicator>());
    rclcpp::shutdown();
    return 0;
}