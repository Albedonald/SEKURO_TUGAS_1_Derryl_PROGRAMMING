#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <iostream>
#include <string>

class ChatterNode : public rclcpp::Node {
public:
    ChatterNode() : Node("chatter_euy")
    {
        RCLCPP_INFO(this->get_logger(), "Chatter Node sudah aktif euy!");
        RCLCPP_INFO(this->get_logger(), "Silakan ketik pesan di bawah dan tekan Enter.");

        publisher_euy = this->create_publisher<std_msgs::msg::String>("/chat", 10);

        timer_euy = this->create_wall_timer(
            std::chrono::milliseconds(100), 
            std::bind(&ChatterNode::timer_input, this)
        );
    }

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_euy;
    rclcpp::TimerBase::SharedPtr timer_euy;

    void timer_input(){
        // Memberikan prompt teks agar user tahu kapan harus mengetik
        std::cout << "\r[Input Pesan]: " << std::flush;

        std::string input;
        // Menggunakan getline agar bisa menerima pesan dengan spasi (misal: "Halo Robot")
        if (std::getline(std::cin, input)) {
            if (input.empty()) return;

            auto message = std_msgs::msg::String();
            message.data = input;

            // Log untuk konfirmasi di terminal publisher
            RCLCPP_INFO(this->get_logger(), "Mengirim: %s", message.data.c_str());
            
            publisher_euy->publish(message);
        }
    }
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    
    // Memberikan instruksi cara stop sebelum spin dimulai
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "Chatter Node Siap. Tekan Ctrl+C untuk berhenti." << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    rclcpp::spin(std::make_shared<ChatterNode>());
    rclcpp::shutdown();
    return 0;
}
/*

Masukkan perintah berikut ke chatter terminal (pakai ubuntu 22.04):

"UNTUK NAVIGASI KE WORKSPACE: "
cd SEKURO_TUGAS_1_Derryl_PROGRAMMING/src/ros_soal_1

"UNTUK BUILD, INSTALL, LALU RUN: "
colcon build
source install/setup.bash
ros2 run package_euy chatter

*/