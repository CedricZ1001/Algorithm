//1、分离连接法（separate chaining）
#include <vector>
#include <list>
using namespace std;

template <typename HashedObj>
class HashTable
{
  public:
    explicit HashTable(int size = 101);

    void makeEmpty()
    {
        for(int i = 0; i < theLists.size(); i++)
            theLists[i].clear();
    }

    bool contains(const HashedObj & x) const
    {
        const list<HashedObj> & whichList = theLists[myhash(x)];
        return find(whichList.begin(), whichList.end(), x) != whichList.end();
    }

    bool remove(const HashedObj & x)
    {
        list<HashedObj> & whichList = theLists[myhash(x)];
        typename list<HashedObj>::iterator itr = find(whichList.begin(), whichList.end(), x);
        if(itr == whichList.end())
            return false;
        whichList.erase(itr);
        --currentSize;
        return true;
    }

    bool insert(const HashedObj & x)
    {
        list<HashedObj> & whichList = theLists[myhash(x)];
        if(find(whichList.begin(), whichList.end(), x) != whichList.end())
            return false;
        whichList.push_back(x);
        if(++currentSize > theLists.size())
            rehash();
        return true;
    }

  private:
    vector<list<HashedObj> > theLists;   // The array of Lists
    int  currentSize;

    void rehash()
    {
        vector<list<HashedObj> > oldLists = theLists;

        // Create new double-sized, empty table
        theLists.resize(2 * theLists.size());
        for(int j = 0; j < theLists.size(); j++)
            theLists[j].clear();

        // Copy table over
        currentSize = 0;
        for(int i = 0; i < oldLists.size(); i++)
        {
            typename list<HashedObj>::iterator itr = oldLists[i].begin();
            while(itr != oldLists[i].end())
                insert(*itr++);
        }
    }

    int myhash(const HashedObj & x) const
    {
        int hashVal = hash(x);

        hashVal %= theLists.size();
        if(hashVal < 0)
            hashVal += theLists.size();

        return hashVal;
    }
};
//2、使用探测法（probing hash tables）
template <typename HashedObj>
class HashTable
{
  public:
    explicit HashTable(int size = 101) : array(size)
    {
        makeEmpty();
    }

    void makeEmpty()
    {
        currentSize = 0;
        for(int i = 0; i < array.size(); i++)
            array[i].info = EMPTY;
    }

    bool contains(const HashedObj & x) const
    {
        return isActive(findPos(x));
    }

    bool insert(const HashedObj & x)
    {
        // Insert x as active
        int currentPos = findPos(x);
        if(isActive(currentPos))
            return false;

        array[currentPos] = HashEntry(x, ACTIVE);

        if(++currentSize > array.size()/2)
            rehash();

        return true;
    }

    bool remove(const HashedObj & x)
    {
        int currentPos = findPos(x);
        if(!isActive(currentPos))
            return false;
        array[currentPos].info = DELETED;
        return true;
    }

    enum EntryType { ACTIVE, EMPTY, DELETED };

  private:
    struct HashEntry
    {
         HashedObj element;
         EntryType info;
         HashEntry(const HashedObj & e = HashedObj(), EntryType i = EMPTY )
           : element(e), info(i) { }
    };

    vector<HashEntry> array;
    int currentSize;

    int findPos(const HashedObj & x) const
    {
        int offset = 1;
        int currentPos = myhash(x);

        while(array[currentPos].info != EMPTY && array[currentPos].element != x)
        {
            currentPos += offset;  // Compute ith probe
            offset += 2;
            if(currentPos >= array.size())
                currentPos -= array.size();
        }
        return currentPos;
    }

    bool isActive(int currentPos) const
    {
        return array[currentPos].info == ACTIVE;
    }

    void rehash()
    {
        vector<HashEntry> oldArray = array;

        // Create new double-sized, empty table
        array.resize(2*oldArray.size());
        for(int j = 0; j < array.size(); j++)
            array[j].info = EMPTY;

        // Copy table over
        currentSize = 0;
        for(int i = 0; i < oldArray.size(); i++)
            if(oldArray[i].info == ACTIVE)
                insert(oldArray[i].element);
    }

    int myhash(const HashedObj & x) const;
};
