#include <SDL2/SDL.h>

template <GameEntity> 
class QuadTree
{
	private:
		QuadTree * northWestChild;
		QuadTree * northEastChild;
		QuadTree * southWestChild;
		QuadTree * southEastChild;
		
	private:
		std::vector<GameEntity*> nodeObjects;
		
	private:
		const int QUAD_TREE_NODE_CAPACITY=4;
		int depth;
		
	private:
		SDL_Rect QuadTreeBoundingBox;
		
		
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
