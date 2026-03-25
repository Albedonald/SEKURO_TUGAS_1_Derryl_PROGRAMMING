#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <iostream>

class DisplayNode : public rclcpp::Node {
public:
    DisplayNode() : Node("display_euy")
    {
        RCLCPP_INFO(this->get_logger(), "Display Node telah berjalan euy! Menunggu pesan: ...");

        using std::placeholders::_1;
        subscription_euy = this->create_subscription<std_msgs::msg::String>(
            "/chat", 
            10,
            std::bind(&DisplayNode::accept_chat, this, _1)
        );
    }

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_euy;
    
    void accept_chat(const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), ">>> PESAN DITERIMA: %s", msg->data.c_str());
    }
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "Display Node Siap. Tekan Ctrl+C untuk berhenti." << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    rclcpp::spin(std::make_shared<DisplayNode>());
    rclcpp::shutdown();
    return 0;
}
/*

Masukkan perintah berikut ke display terminal (pakai ubuntu 22.04):

"UNTUK NAVIGASI KE WORKSPACE: "
cd SEKURO_TUGAS_1_Derryl_PROGRAMMING/src/ros_soal_1

"UNTUK BUILD, INSTALL, LALU RUN: "
colcon build
source install/setup.bash
ros2 run package_euy display

*/