#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "opencv2/opencv.hpp"
#include "cv_bridge/cv_bridge.h"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"

using namespace cv;
using namespace std::chrono_literals;
using namespace std;
using std::placeholders::_1;

Size size_(640, 480);

VideoCapture camsrc_(0);

// ty codenya mas hehe

/* void publishImage(Mat result, rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisherImage_)
{
    auto img_msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", result).toImageMsg();
    publisherImage_->publish(*img_msg);
}
*/

class YoloPublisher : public rclcpp::Node
{
public:
    YoloPublisher() : Node("yolopublisher")
    {
        camsrc_.set(CAP_PROP_FRAME_WIDTH, 640);
        camsrc_.set(CAP_PROP_FRAME_HEIGHT, 480);
        publisher_ = this->create_publisher<sensor_msgs::msg::Image>("cam_image", 10);
        timer_ = this->create_wall_timer(10ms, std::bind(&YoloPublisher::publish_image, this));
    }

private:
    void publish_image()
    {
        Mat image, frame;
        camsrc_.read(frame);

        if(!frame.empty()) {
            resize(frame, image, size_);
            imshow("Normal", image);
            imshow("Frame", frame);
            // imshow("My window", maskHSV);

            auto img_msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", image).toImageMsg();
            publisher_->publish(*img_msg);
            RCLCPP_INFO(this->get_logger(), "Data published.");
        }
        waitKey(1);
    }

    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
    sensor_msgs::msg::Image::SharedPtr message;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<YoloPublisher>());
    rclcpp::shutdown();
    return 0;
}