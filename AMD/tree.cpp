#include <AMD/tree.hpp>
#include <iostream>

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

bool Tree::equal (const boost::shared_ptr<Tree>& t1,
                 const boost::shared_ptr<Tree>& t2) const
{
    if (t1 == t2) return true;

    if (!t1 || !t2) return false;

    return (t1->d_info == t2->d_info) &&
           equal(t1->d_left,t1->d_left) &&
           equal(t1->d_right,t1->d_right);
}

bool Tree::operator==(const Tree& other) const
{
    return (other.d_info == this->d_info) &&
           (equal(other.d_left,this->d_left)) &&
           (equal(other.d_right,this->d_right));
}

bool Tree::operator!=(const Tree& other) const
{
    return !(*this == other);
}

} } // namespace AMD::detail
