### [C++ algorithm：lower_bound & upper_bound](https://yuihuang.com/cpp-algorithm-lower-bound-upper-bound/)
* 【筆記】常用C++ algorithm：```lower_bound & upper_bound```
* 【用途】針對「已經排序」的資料進行binary search。
  * ```vector <int> v;```
  * ```sort(v.begin(), v.end());```
* ```lower_bound```：找出vector中「大於或等於」val的「最小值」的位置：
  * ```auto it = lower_bound(v.begin(), v.end(), val);```
* ```upper_bound```：找出vector中「大於」val的「最小值」的位置：
  * ```auto it = upper_bound(v.begin(), v.end(), val);```
