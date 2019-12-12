//
// Created by sean on 12/11/19.
//

#include "PlainBox.h"
enum Color {BLACK, RED, GREEN, YELLOW, WHITE};
template <typename Itemtype>
class ToyBox: public plainbox<Itemtype>
{
    public:
      typedef std::shared_ptr<ToyBox> Ptr;

      ToyBox(){};

      ToyBox(const Itemtype in_type, const Color in_color)
       :plainbox<Itemtype>(in_type), boxcolor(in_color){};

      Color GetColor(){ return boxcolor;}
    private:
     Color boxcolor;
};
