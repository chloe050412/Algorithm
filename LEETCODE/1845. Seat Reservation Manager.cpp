#include <vector>

class SeatManager 
{
public:
    SeatManager(int n)
    {
        _seats.resize(n);
        _index = 1;
    }

    int reserve() 
    {
        if (_canceled.empty())
        {
             _seats[_index - 1] = _index;
             ++_index;
             return _index;
        }
        else
        {
            int min = _canceled[0];
            for (int i = 0; i < _canceled.size(); ++i)
            {
                if (_canceled[i] < min)
                {

                }
            }
            return *_canceled.begin();
        }
    }

    void unreserve(int seatNumber) 
    {
        _seats[seatNumber-1] = 0;
        _canceled.push_back(_index);
        --_index;
    }

private:
    std::vector<int> _seats;
    std::vector<int> _canceled;
    int _index;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

int main()
{
    SeatManager* man = new SeatManager(4);
    int a1 = man->reserve();
	int a2 = man->reserve();
    man->unreserve(2);
	int a3 = man->reserve();
	int a4 = man->reserve();
	int a5 = man->reserve();
	int a6 = man->reserve();
	man->unreserve(5);


    return 0;
}
