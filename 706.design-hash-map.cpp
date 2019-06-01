/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] Design HashMap
 */

#include <tuple>
#include <vector>
#include <algorithm>
class MyHashMap
{
public:
    /** Initialize your data structure here. */
    using vecPair = std::vector<std::pair<int, int>>;
    vecPair m;
    MyHashMap()
    {
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        auto i = find(key);
        if (i == m.cend())
        {
            m.push_back(std::make_pair(key, value));
        }
        else
        {
            i->second = value;
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        auto i = find(key);
        if (i != m.cend())
        {
            return i->second;
        }
        else
        {
            return -1;
        }
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        auto i = find(key);
        if (i != m.cend())
        {
            m.erase(i);
        }
    }

    vecPair::iterator find(int key)
    {
        return std::find_if(m.begin(), m.end(), [key](std::pair<int, int> p) { return p.first == key; });
    }
};

//find 与find_if有什么区别呢
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// √ Accepted
//   √ 33/33 cases passed (292 ms)
//   √ Your runtime beats 60.46 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (41 MB)
