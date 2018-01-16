vector<int> order;
vector<int> temorder;
vector<int>temp;
void merge (vector<int> &nums, int beg, int end)
{
    int mid = beg + end/2;
    int a1 = beg, a2 = mid+1;
    int i = beg;
    while (a1<mid && a2<end)
    {
        if(nums[a1]>=nums[a2])
        {
            temp[i] = nums[a1];
            temorder[i] = temp[a1];
            a1++;

        }
        else
        {
            temp[i] = nums[a2]; a2++;
            temorder[i] = temp[a2];

        }
        i++;
    }
    copy(temorder+beg,temorder+ end, order+beg);
}
void sort (vector<int> &nums, int beg, int end)
{
    if (end-beg > 1) {
        sort(nums,beg,(beg + end)/2);
        sort(nums,(beg + end)/2+1, end);
    }
    merge(nums, beg, end);
}
vector<int> countSmaller(vector<int> &nums) {
    order = vector<int>(nums.size());
    temorder = vector<int>(nums.size());
    temp = vector<int>(nums.size());
    int i =0;

    for (auto it : order)
        it = i++;
    sort(nums,0,nums.size());
    vector<int> count(nums.size());
    i = len
    for (auto it:order)
        count[order]

}
