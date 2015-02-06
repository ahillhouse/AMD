#include <AMD/tree.hpp>

#define BOOST_TEST_MODULE TreeTest
#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

BOOST_AUTO_TEST_CASE ( Equal )
{
	typedef class AMD::detail::Tree Tree;
    Tree testTree("M",boost::shared_ptr<Tree>(),boost::shared_ptr<Tree>());
    Tree testTree2("M",boost::shared_ptr<Tree>(),boost::shared_ptr<Tree>());
    Tree testTree3("M",boost::shared_ptr<Tree>(boost::make_shared<Tree>(testTree2)),
    	           boost::shared_ptr<Tree>());
    Tree testTree4("M",boost::shared_ptr<Tree>(boost::make_shared<Tree>(testTree2)),
    	           boost::shared_ptr<Tree>());
    Tree testTree5("N",boost::shared_ptr<Tree>(boost::make_shared<Tree>(testTree2)),
    	           boost::shared_ptr<Tree>());

	BOOST_CHECK (testTree == testTree2);
	BOOST_CHECK (!(testTree == testTree3));
    BOOST_CHECK (testTree3 == testTree4);
    BOOST_CHECK (!(testTree == testTree5));

}


BOOST_AUTO_TEST_CASE ( NotEqual )
{
	typedef class AMD::detail::Tree Tree;
    Tree testTree("M",boost::shared_ptr<Tree>(),boost::shared_ptr<Tree>());
    Tree testTree2("M",boost::shared_ptr<Tree>(),boost::shared_ptr<Tree>());
    Tree testTree3("M",boost::shared_ptr<Tree>(boost::make_shared<Tree>(testTree2)),
    	           boost::shared_ptr<Tree>());
    Tree testTree4("M",boost::shared_ptr<Tree>(boost::make_shared<Tree>(testTree2)),
    	           boost::shared_ptr<Tree>());
    Tree testTree5("N",boost::shared_ptr<Tree>(boost::make_shared<Tree>(testTree2)),
    	           boost::shared_ptr<Tree>());

   BOOST_CHECK (!(testTree != testTree2));
   BOOST_CHECK (testTree != testTree3);
   BOOST_CHECK (!(testTree3 != testTree4));
   BOOST_CHECK (testTree != testTree5);

}

