#include <gtest/gtest.h>

#include <bflib/container/graph.h>

#include <iostream>
#include <stdexcept>

TEST(Graph, CreateTest) {
    bflib::Graph<int> g;

    auto n1 = g.AddNode(1);
    auto n2 = g.AddNode(2);

    ASSERT_NE(n1, n2);

    g.AddEdge(n1, n2, 0.0);
}

TEST(Graph, NodeIndexDiffersTest) {
    bflib::Graph<int> g;

    auto n1 = g.AddNode(1);
    auto n2 = g.AddNode(2);

    ASSERT_NE(n1, n2);
}

TEST(Graph, AddEdgeTest) {
    bflib::Graph<int> g;

    auto n1 = g.AddNode(1);
    auto n2 = g.AddNode(2);
    auto n3 = g.AddNode(3);

    g.AddEdge(n1, n2, 0.0);
    g.AddEdge(n1, n3, 0.0);

    // TODO Order independent test
    auto edges = g.GetEdges(n1);

    ASSERT_EQ(2, edges.size());
    EXPECT_EQ(n2, edges[0].first);
    EXPECT_EQ(n3, edges[1].first);
}

TEST(Graph, GetEdgesInvalidNodeTest) {
    bflib::Graph<int> g;

    // TODO Order independent test
    ASSERT_THROW(g.GetEdges({}), std::out_of_range);
}