#include <iostream>
#include <map>
#include "Utils.h"

namespace inputs
{
    VisualOutput *visual_process(char *buffer, int data_length)
    {
        VisualOutput *output = new VisualOutput();
        int a = 0;
        for (int i = 0; i < data_length; i++)
        {
            if (i == 2)
                a = (int)buffer[i];
            // std::cout << (int)buffer[i] << std::endl;
        }
        switch (a)
        {
        case 0:
            std::cout << "Received from model: " << "no_objects" << std::endl;
            break;
        case 1:
            std::cout << "Received from model: " <<"left" << std::endl;
            break;
        case 2:
            std::cout << "Received from model: " << "mid" << std::endl;
            break;
        case 3:
            std::cout << "Received from model: " << "right" << std::endl;
            break;
        case 4:
            std::cout << "Received from model: " << "all" << std::endl;
            break;
        case 5:
            std::cout << "Received from model: " << "left_mid" << std::endl;
            break;
        case 6:
            std::cout << "Received from model: " << "right_mid" << std::endl;
            break;
        default:
            std::cout << "invalid data, discarding" << std::endl;
            break;
        }
        output->prediction = a;
        return output;
    }
    Sensor1Output *sensor1_process(char *buffer, int data_length)
    {
        Sensor1Output *output = new Sensor1Output();
        int item_count = (int)buffer[0];
        int a[item_count];
        int i = 0, j = 1;

        while (j < data_length)
        {
            int item_size = (int)buffer[j];
            j++;
            a[i] = (int)buffer[j];
            i++;
            j++;
        }

        std::cout << "item count: " << item_count << std::endl;
        for (int i = 0; i < item_count; i++)
        {
            std::cout << "item " << i << ": " << a[i] << std::endl;
        }
        return output;
    }
}