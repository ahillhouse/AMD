#include <AMD/tree.hpp>

#define BOOST_TEST_MODULE TreeTest
#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

BOOST_AUTO_TEST_CASE ( Equal )
{
    typedef class AMD::detail::Tree Tree;
    boost::shared_ptr<Tree> nil;
    boost::shared_ptr<Tree> node1 = boost::make_shared<Tree>("M",nil,nil);
    boost::shared_ptr<Tree> node2 = boost::make_shared<Tree>("M",nil,nil);
    boost::shared_ptr<Tree> node3 = boost::make_shared<Tree>("N",nil,nil);
    boost::shared_ptr<Tree> node4 = boost::make_shared<Tree>("O",node1,node1);
    boost::shared_ptr<Tree> node5 = boost::make_shared<Tree>("O",node1,node2);
    boost::shared_ptr<Tree> node6 = boost::make_shared<Tree>("O",node1,node3);
    boost::shared_ptr<Tree> node7 = boost::make_shared<Tree>("P",node5,nil);
    boost::shared_ptr<Tree> node8 = boost::make_shared<Tree>("P",node4,nil);

    BOOST_CHECK (*node1 == *node2);
    // Single equal node
    BOOST_CHECK (!(*node1 == *node3));
    // Single unequal node
    BOOST_CHECK (*node4 == *node5);
    // Different tree with different children pointers that hold same values
    BOOST_CHECK (!(*node4 == *node6));
    // Same value in root but different children values
    BOOST_CHECK (!(*node7 == *node6));
    // Different depths
    BOOST_CHECK (*node8 == *node7);
    // Deeper trees.  Different children pointers with same values
}


BOOST_AUTO_TEST_CASE ( notEqual )
{
    typedef class AMD::detail::Tree Tree;
    boost::shared_ptr<Tree> nil;
    boost::shared_ptr<Tree> node1 = boost::make_shared<Tree>("M",nil,nil);
    boost::shared_ptr<Tree> node2 = boost::make_shared<Tree>("M",nil,nil);
    boost::shared_ptr<Tree> node3 = boost::make_shared<Tree>("N",nil,nil);
    boost::shared_ptr<Tree> node4 = boost::make_shared<Tree>("O",node1,node1);
    boost::shared_ptr<Tree> node5 = boost::make_shared<Tree>("O",node1,node2);
    boost::shared_ptr<Tree> node6 = boost::make_shared<Tree>("O",node1,node3);
    boost::shared_ptr<Tree> node7 = boost::make_shared<Tree>("P",node5,nil);
    boost::shared_ptr<Tree> node8 = boost::make_shared<Tree>("P",node4,nil);

    BOOST_CHECK (!(*node1 != *node2));
    // Single equal node
    BOOST_CHECK (*node1 != *node3);
    // Single unequal node
    BOOST_CHECK (!(*node4 != *node5));
    // Different tree with different children pointers that hold same values
    BOOST_CHECK (*node4 != *node6);
    // Same value in root but different children values
    BOOST_CHECK (*node7 != *node6);
    // Different depths
    BOOST_CHECK (!(*node8 != *node7));
    // Deeper trees.  Different children pointers with same values
}

