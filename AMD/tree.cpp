#include <AMD/tree.hpp>
#include <stdio.h>

namespace AMD { namespace detail {

Tree::Tree (const std::string& info, 
            const boost::shared_ptr<Tree>& left, 
            const boost::shared_ptr<Tree>& right)
{
    this->d_info = info;
    this->d_left = left;
    this->d_right = right;
}
                   
Tree::~Tree()
{

}

void swap(Tree& other)
{

}

std::string Tree::info() const
{
    return this->d_info;
}

void Tree::setInfo(const std::string& info)
{
    this->d_info = info;
}

bool Tree::operator==(const Tree& other) const
{
    if (other.d_info != this->d_info) return false;

    if ((other.d_right == this->d_right) && (other.d_left == this->d_left))
        return true;

    if ((!(other.d_right) && this->d_right) 
         || (other.d_right && !(this->d_right))
         || (!(other.d_left) && this->d_left)
         || (other.d_left && !(this->d_left))) return false;

    if (!other.d_right && !other.d_right) 
        return *(other.d_left) == *(this->d_left);
    else if (!other.d_left && !this->d_left) 
        return *(other.d_right) == *(this->d_right);
    else
    {
        return (*(other.d_right) == *(this->d_right))
           && (*(other.d_left) == *(this->d_left));
    }
}

bool Tree::operator!=(const Tree& other) const
{
    return !(*this == other);
}

} } // namespace AMD::detail
