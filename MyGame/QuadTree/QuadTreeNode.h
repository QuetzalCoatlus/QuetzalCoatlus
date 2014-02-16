#include <SDL2/SDL.h>
#include <SdlRectCollision.h/SdlRectCollision.h>

template <GameEntity> 
class QuadTreeNode
{		
	private:
		std::vector<GameEntity*> nodeObjects;
		std::vector<QuadTreeNode*> nodeChildren;
		
	private:
		const int QuadTreeNodeCapacity=4;
		
	private:	
		int nodeDepth;
		QuadTreeNode * parentNode;
		
	private:
		SDL_Rect * nodeBoundingBox;
		
		
	public:
		QuadTree(const int);
		
	public:	
		void Split();
		bool Insert(GameEntity*,bool,int);
		bool Remove(GameEntity*);
		bool NodeCollision(GameEntity*);
		bool ChildCollision(GameEntity*);
		void SetBoundingBox(SDL_Rect*);
		std::vector<QuadTreeNode*> * GetNodeChildren();
		std::vector<GameEntity*> * GetNodeObjects();
		QuadTreeNode * GetParentNode();
		void DestroyQuadTree();
		
	public:
		bool HasChildren();
		bool IsFull();
		bool IsLeaf();
		bool CanSplit(const int max_size);
		bool CanSplit();
		
	private:
		void SetParent(QuadTreeNode*);
};
