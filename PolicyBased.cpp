#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;

ordered_set os;


typedef tree<
    Key,                            // 1. Type of elements (like int)
    Mapped,                         // 2. Mapped type (like null_type for set)
    Compare,                        // 3. Comparison function
    Tag,                            // 4. Underlying tree type
    Node_Update>                    // 5. Update policy (for order stats)
CustomName;

tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pair_set; // when you want to modify the data type structure



2. Use less_equal<int> for multiset behavior (fake multiset)
Standard PBDS does not support true duplicates, but you can simulate it using pair<int, int> (like adding an index):


typedef tree<
    pair<int, int>,               // Pair: {value, index}
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_multiset;
Example insertion:

ordered_multiset os;
int index = 0;
os.insert({value, index++});


5. Custom comparator
For example, for reverse ordering:

typedef tree<
    int,
    null_type,
    greater<int>,               // Reverse order
    rb_tree_tag,
    tree_order_statistics_node_update>
reversed_ordered_set;






