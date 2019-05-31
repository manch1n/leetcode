/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] Design HashSet
 */
//由于大多时候不用自己设计哈希表，我就简单的弄个vector的封装加stl就好了。
// 开放定址法与链式法有设计过
#include <vector>
#include <algorithm>
class MyHashSet
{
public:
    /** Initialize your data structure here. */
    std::vector<int> container;
    MyHashSet()
    {
    }

    void add(int key)
    {
        if (!contains(key))
        {
            container.push_back(key);
        }
    }

    void remove(int key)
    {
        for (int i = 0; i < container.size(); ++i)
        {
            if (key == container[i])
            {
                container.erase(container.begin() + i);
                break;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        if (std::find(container.begin(), container.end(), key) != container.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// √ Accepted
//   √ 28/28 cases passed (400 ms)
//   √ Your runtime beats 12.3 % of cpp submissions
//   √ Your memory usage beats 99.15 % of cpp submissions (35.8 MB)