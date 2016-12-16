#ifndef BFLIB_CONTAINER_GRAPH_H
#define BFLIB_CONTAINER_GRAPH_H

#include <map>
#include <vector>
#include <limits>
#include <unordered_set>

namespace bflib {

    //! Graph defines a directed, weighted graph class.
    //! The class is safety optimized, but not performance or space optimized.
    //! Lots of bound checks are implemented.
    template<typename NodeType>
    class Graph {
    public:
        typedef size_t NodeIndex;
        typedef size_t EdgeIndex;

        class Iterator;

        Graph() {};

        //! Add a new node to the graph
        NodeIndex AddNode(const NodeType& node) {
            if (index_ == std::numeric_limits<long long>::max()) {
                throw std::out_of_range("Maximum number of nodes reached");
            }

            adjacents_.emplace_back(node);

            auto idx = ++index_;
            
            index_map_[idx] = adjacents_.size()-1;

            return idx;
        }

        //! Add new edge from node to node with some value and weight
        //! \throws std::out_of_range if from or to are invalid
        void AddEdge(const NodeIndex& from, const NodeIndex& to, float weight = 0.0) {
            // check uniqueness. are multiple edges allowed?
            adjacents_[Idx(from)].AddEdge(to, weight);
        }

        const std::vector<std::pair<NodeIndex, float>>& GetEdges(const NodeIndex& from) const {
            return adjacents_[Idx(from)].points_to;
        }

        // std::vector<Graph> ConnectedComponents();

                // std::pair<Iterator, Iterator> DepthFirstSearch(const NodeIndex& start_node);
        // std::pair<Iterator, Iterator> BreadthFirstSearch(const NodeIndex& start_node);
        // std::pair<Iterator, Iterator> MinimumSpanningTree();

        class DepthFirstSearchIterator {
        public:
            DepthFirstSearchIterator(const Graph<NodeType>& graph, const NodeIndex& start)
                : g_(graph), visit_list_({start}) {
            }

            NodeIndex operator*() const {
                return visit_list_.back();
            }

            DepthFirstSearchIterator& operator++() {
                

                return *this;
            }
            
            DepthFirstSearchIterator operator++(int) {
                DepthFirstSearchIterator tmp(*this);
                operator++();
                return tmp;
            }
            
        private:
            const Graph& g_;
            std::vector<NodeIndex> visit_list_;
            std::unordered_set<NodeIndex> visited_list_;
        };

    private:
        struct AdjacencyEntry {

            AdjacencyEntry(const NodeType& node) {
                this->node = node;
            }

            NodeType node;
            std::vector<std::pair<NodeIndex, float>> points_to;

            void AddEdge(const NodeIndex& to, float weight) {
                points_to.emplace_back(to, weight);
            }
        };

        size_t Idx(const NodeIndex& from) const {
            return index_map_.at(from);
        }

        long long index_ = 0;

        // hash for interconnections. Isomorphic graphs should have the same hash
        // https://pdfs.semanticscholar.org/03ce/51abee2549f640c483c666516d3fc6053e32.pdf
        // https://arxiv.org/ftp/arxiv/papers/1606/1606.00001.pdf
        // https://eprint.iacr.org/2012/352.pdf
        size_t graph_hash_;

        std::map<long long, size_t> index_map_;
        std::vector<AdjacencyEntry> adjacents_;
    };
}

#endif // BFLIB_CONTAINER_GRAPH_H
