#include <QCoreApplication>

#include <iostream>
#include <fstream>
#include <chrono>
#include <unistd.h>

#include "decoder.h"


void spinner() {
    static int pos{0};
    const char cursor[4]{'|', '/', '-', '\\'};
    std::cout << "\r" << cursor[pos] << std::flush;
    pos = (pos + 1) % 4;
}

void function(const std::string fileName) {
    ChannelMap pre;
    Decoder decoder(fileName, pre);
    auto pos{decoder.positionsOfCMAPHeaders()};
    std::cout << pos.size() << std::endl;
}

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);


    auto start = std::chrono::steady_clock::now();
    function("/home/egor/shares/tmp/proba_t2_thin_1");
//    function("/home/egor/shares/tmp/kp_dynamic_1_tmp");
    auto stop = std::chrono::steady_clock::now();
    std::cout << "Time elapsed, ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << std::endl;
    return 0;
//    return a.exec();
}
