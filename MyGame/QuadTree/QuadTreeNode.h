#include <SDL2/SDL.h>
#include <SdlRectCollision.h/SdlRectCollision.h>

template <GameEntity> 
class QuadTreeNode
{		
	private:
		std::vector<GameEntity*> nodeObjects;
		std::vector<QuadTreeNode*> nodeChildren;
		
	private:
		const int QUAD_TREE_NODE_CAPACITY=4;
		
	private:	
		int nodeDepth;
		QuadTreeNode * parentNode;
		
	private:
		SDL_Rect NodeBoundingBox;
		
		
	public:
		QuadTree(const int);
		
	public:	
		void Split();
		bool Insert(GameEntity*,bool);
		bool Remove(GameEntity*);
		bool NodeCollision(GameEntity*);
		bool ChildCollision(GameEntity*)
		void DestroyQuadTree();
		
	public:
		bool HasChildren();
		bool IsFull();
		bool IsLeaf();
		bool CanSplit(const int max_size);
		bool CanSplit();
		
	private:
		void SetParent(QuadTreeNode*);
		void SetBoundingBox(SDL_Rect*);
};
