#include <map>
#include <string>
#include <iostream>

/* C++内置哈希表试用 */
/* 
 * 主要分为两种: map 和 unordered_map
 * map: 有序哈希表
 * unordered_map: 无序哈希表
 */

int main()
{
    // 创建一个有序哈希表
    std::map<int, std::string> map;
    map[2001] = "one";
    map[2132] = "two";
    map[1648] = "three";
    map[2] = "four";

    // 打印哈希表
    for (auto it = map.begin(); it != map.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }

}