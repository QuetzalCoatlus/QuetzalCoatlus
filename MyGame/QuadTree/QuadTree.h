template <GameEntity> 
class QuadTree
{
	private:
		QuadTree * northWestChild;
		QuadTree * northEastChild;
		QuadTree * southWestChild;
		QuadTree * southEastChild;
		
	private:
		const int QUAD_TREE_NODE_CAPACITY=4;
		
		int depth;
		
	public:
		QuadTree(const int);
		
	public:	
		void Split();
		bool Insert(GameEntity*);
		bool Remove(GameEntity*);
		bool NodeCollision(GameEntity*);
		bool ChildCollision(GameEntity*)
		void DestroyQuadTree();
		
	private:
		bool HasChildren();
		bool IsFull();
		bool CanSplit();
};
