#include "Solution.h"

vector<int> Solution::twoSum(vector<int>& nums, int target){
    map<int,int> mymap;
	for(int i=0;i<nums.size();i++){
		mymap.insert(pair<int,int>(i,nums[i]));
	}
	vector<int> result;
	int left=0, right=nums.size()-1;
	sort(nums.begin(), nums.end());
	while(nums[left]+nums[right]!=target){
		if(nums[left]+nums[right]>target)right--;
		else left++;
	}
    for(map<int,int>::iterator it=mymap.begin();it!=mymap.end();it++){
        if(it->second==nums[left]||it->second==nums[right])result.push_back(it->first);
    }
	return result;
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2){
	ListNode* head=NULL,*prev=NULL;
	int carry=0;
	while(l1||l2){
		int v1=l1?l1->val:0;
		int v2=l2?l2->val:0;
		ListNode* curr = new ListNode((v1+v2+carry)%10);
		carry = (v1+v2+carry)/10;
		if(!head) head = curr;
		if(prev) prev->next = curr;
		prev = curr;
		l1 = l1?l1->next:NULL;
		l2 = l2?l2->next:NULL;
	}
	if(carry){
		ListNode* end = new ListNode(carry);
		prev->next = end;
	}
	return head;
}

int Solution::lengthOfLongestSubstring(string s){
    if(s.empty()) return 0;
    int p1 = 0, p2 = 1;
    int maxLen = p2 - p1;
    for(; p2 < s.length(); ++p2) {
        int i = p1;
        for(; i < p2; ++i) {
            if(s[i] == s[p2]) {
                p1 = i + 1;
                break;
            }
        }
        maxLen = max(maxLen, p2 - p1 + 1);
    }
    return maxLen;
}

string Solution::multiply(string num1,string num2){
	size_t len1 = num1.size();
	size_t len2 = num2.size();
	//make sure num1 is larger than num2
	if(len2>len1){
		string temp = num1;
		num1=num2;
		num2=temp;
		len1=num1.size();
		len2=num2.size();
	}

	string result (len1+len2,'0');
	int carry = 0;

	for (int i=len2-1;i>=0;i--){
		for (int j = len1-1; j >=0; j--)
		{
			carry+=int(result[i+j+1]-'0');
			result[i+j+1] =  (int(num1[j]-'0')*int(num2[i]-'0')+carry)%10+'0';
			carry = (int(num1[j]-'0')*int(num2[i]-'0')+carry)/10;
		}
		if(carry){result[i]=carry+'0'; carry=0;}
	}
	int i=0;
	while(result[i]=='0'&&i<result.size()-1)i++;
	result=result.substr(i);
	return result;
}

vector<vector<int>> Solution::permute(vector<int>& nums) {
    vector<vector<int>> results;
	vector<int> permutation;
    assign(results,permutation,nums,false);
    return results;
}

vector<vector<int>> Solution::permuteUnique(vector<int>& nums){
	vector<vector<int>> results;
	vector<int> permuteUni;
	sort(nums.begin(),nums.end());
	assign(results,permuteUni,nums,true);
	return results;
}

int Solution::maxSubArray(vector<int>& nums){
	if(nums.size()==1)return nums[0];
	size_t head=0,end=nums.size()-1;
	int max = nums[head];
	while(nums[head]<0&&head<nums.size()){if(nums[head]>max)max=nums[head];head++;}
	if(head==nums.size())return max;
	while(nums[end]<0)end--;
	size_t forward=head;
	int result = nums[head],curr = nums[head];
	while(++forward<=end){
		while(nums[forward]<0)curr+=nums[forward++];
		if(curr>0) curr=curr+nums[forward];
		else curr = nums[forward];
		if(curr>result) result=curr;
	}
	return result;
}

void Solution::rotate(vector<vector<int>>& matrix){
	rotateMatrix(matrix,true);
	return;
}

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs){
	map<string,vector<string>> mymap;
	for(int i=0;i<strs.size();i++){
		string str = strs[i];
		sort(str.begin(),str.end());
		map<string,vector<string>>::iterator it = mymap.find(str);
		if(it == mymap.end()){
			vector<string> vec;
			vec.push_back(strs[i]);
			mymap.insert(pair<string,vector<string>>(str,vec));
		}
		else it->second.push_back(strs[i]);
	}
	vector<vector<string>> result;
	for(map<string,vector<string>>::iterator mit =mymap.begin();mit!=mymap.end();mit++){
		result.push_back(mit->second);
	}
	return result;
}

double Solution::myPow(double x, int n){
   	double pow = 1;
	bool neg = false;
	if(n==0||x==1.0)return 1.0;
	else if (x==-1){
	    if(n%2==0)return 1.0;
	    else return -1.0;
	}
	else{
		if(n<0&&n>-2147483648){neg=true;n*=-1;}
		else if(n==-2147483648&&x>1.0)return 0;
		for(int i=0;i<n;i++){
		    if(pow==0)return 0;
			pow *= x;
		}
		if(neg)return 1/pow;
		else return pow;
	}
}

vector<int> Solution::spiralOrder(vector<vector<int>>& matrix){
    vector<int> result;
    if(matrix.empty())return result;
  	while(matrix.size()>1&&matrix[0].size()>1) readEdge(matrix,result);
  	if(matrix.size()==1){
		for(size_t i=0;i<matrix[0].size();i++)result.push_back(matrix[0][i]);
  	}
    else if(matrix[0].size()==1){
        for(size_t i=0;i<matrix.size();i++)result.push_back(matrix[i][0]);
    }
	return result;
}

bool Solution::canJump(vector<int>& nums){
	int pos=0,goal=0;
    while(pos==0||pos<=goal&&goal<nums.size()){
        goal=max(pos+nums[pos],goal);
        pos++;
    }
    return goal>=nums.size()-1;
}

vector<vector<int>> Solution::generateMatrix(int n){
	vector<vector<int>> matrix(n,std::vector<int>(n));
	int x=0,y=0,left=0,right=n-1,top=0,bottom=n-1;
	for(int i=1;i<=n*n;i++){
		//cout << i << " " << x << y << " " << left << right << top << bottom << endl;
		matrix[x][y]=i;
		if(x==top&&y<right)y++;
		else if(y==right&&x<bottom)x++;
		else if(x==bottom&&y>left)y--;
		else if(y==left&&x>top)x--;

		if(i!=1&&x==top&&y==left){x++;y++;left++;right--;top++;bottom--;}
	}
	return matrix;
}

string Solution::getPermutation(int n,int k){
    string res;
    vector<int> vec;
    int temp=1;
    for(int i=1;i<n;i++){temp*=i; vec.push_back(i);}
    vec.push_back(n);
    k-=1;
    for(int i=1;i<=n;i++){
        res+=to_string(vec[k/temp]);
        vec.erase(vec.begin()+k/temp);
        k=k%temp;
        if(n-i)temp/=(n-i);
    }
    return res;
}

void Solution::assign(vector<vector<int>>& results, vector<int> permut, vector<int> remain,bool unique){
	//cout << remain.size() << endl;
	if(remain.size()==1){
   		permut.push_back(remain[0]);
   		results.push_back(permut);
   		//cout << "Gotcha" << endl;
   		return;
   	}
   	else {
   		for(int i=0;i<remain.size();i++){
   			if(unique&&i>0&&remain[i]==remain[i-1])continue;
   			vector<int> new_permut = permut;
   			new_permut.push_back(remain[i]);
   			vector<int> new_remain = remain;
   			new_remain.erase(new_remain.begin()+i);
   			assign(results,new_permut,new_remain,unique);
   		}
   	}
   	return;
}

void Solution::readEdge(vector<vector<int>>& matrix, vector<int>& result){
	for(size_t i=0;i<matrix[0].size();i++) result.push_back(matrix[0][i]);
	for(size_t i=1;i<matrix.size()-1;i++) result.push_back(matrix[i][matrix[i].size()-1]);
	for(int i=matrix[matrix.size()-1].size()-1;i>=0;i--) result.push_back(matrix[matrix.size()-1][i]);
	for(int i=matrix.size()-2;i>0;i--) result.push_back(matrix[i][0]);
	if(matrix.size()>1&&matrix[0].size()>1){
		matrix.pop_back();
		matrix.erase(matrix.begin());
		for(size_t i=0;i<matrix.size();i++){
			matrix[i].pop_back();
			matrix[i].erase(matrix[i].begin());
		}
	}
	else matrix.clear();
}

void Solution::rotateMatrix(vector<vector<int>>& matrix, bool clockwise){
	if(matrix.size()==1)return;
	//if true, rotate clockwise, else rotate countclockwise.
	if(clockwise){
		for(int i=0;i<matrix.size()-1;i++){
			for(int j=i+1;j<matrix.size();j++){
				iter_swap(matrix[i].begin()+j,matrix[j].begin()+i);
			}
		}
	for(int i=0;i<matrix.size();i++)reverse(matrix[i].begin(),matrix[i].end());
	}
	else{
		for(int i=0;i<matrix.size();i++)reverse(matrix[i].begin(),matrix[i].end());
		for(int i=0;i<matrix.size()-1;i++){
			for(int j=i+1;j<matrix.size();j++){
				iter_swap(matrix[i].begin()+j,matrix[j].begin()+i);
			}
		}
	}
	return;
}