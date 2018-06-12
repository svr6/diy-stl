
class Solution {
public:
  
    typedef struct
    {
        int left;
        int right;
    }value;
    
    typedef vector<int> VecInt;
    typedef map<int, value> HashMap;
    
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        VecInt result;
        HashMap hash_map;
        
        VecInt::iterator iter = nums.begin();
        for(int index=0; iter != nums.end(); iter++,index++)
        {
            HashMap::iterator iter2 = hash_map.find(*iter);
            if(iter2 != hash_map.end())
            {      
                //if (iter2->second.right >= 0)
                {
                    if (index == iter2->second.right)
                    {
                        cout << "error: repeating element!\n"<< endl;
                        exit(-1);
                    }
                    result.push_back(index < iter2->second.right ? index : iter2->second.right);
                    result.push_back(index > iter2->second.right ? index : iter2->second.right);
                    
                    return result;
                }
            }else
            {
                value node = value{0, 0};
                node.right = index;
                int rvalue = target - *iter;
                hash_map.insert(pair<int, value>(rvalue, node));
            } 
        }
        
        return result; 
    }
    
    void IterMap (HashMap& m)
    {
        HashMap::iterator iter = m.begin();
        for( ;iter != m.end(); iter++)
        {
            cout << to_string(iter->second.left) << endl;
            cout << to_string(iter->second.right) << endl;
        }
    }
};


