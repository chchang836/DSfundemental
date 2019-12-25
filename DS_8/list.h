//
// Created by sean on 12/23/19.
//

#ifndef DS8_LIST_H
#define DS8_LIST_H
#include <memory>

template <class ItemType>
class ListInterface {
    public:
        ListInterface(){};
        virtual bool isEmpty() const = 0;
        virtual int getLength() const = 0;
        virtual bool insert(int position, const ItemType& entry) = 0;
        virtual bool remove(int position) = 0;
        //virtual void clear() = 0;
        virtual ItemType replace(int position, const ItemType& entry) = 0;
        virtual ItemType getEntry (int position) const = 0;
        virtual ~ListInterface() {};
};

template <class ItemType>
class ArrayList : public ListInterface<ItemType>
{
    public:
     typedef std::shared_ptr<ArrayList> Ptr;

      ArrayList(): ListInterface<int>() {
          maxItems = DEFAULT_SIZE;
      };

      //void clear();

      bool isEmpty() const;

      int getLength() const;

      bool insert(int position, const ItemType& entry);

      bool remove(int position);

      ItemType getEntry(int position) const throw();

      ItemType replace(int position, const ItemType& entry) throw();

    private:
      static const int DEFAULT_SIZE = 100;
      ItemType items[DEFAULT_SIZE+1];
      int itemCount;
      int maxItems;
};



#endif //DS8_LIST_H
