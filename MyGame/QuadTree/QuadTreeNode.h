#ifndef _QUADTREENODE_H_
	#define _QUADTREENODE_H_

#include <vector>
#include <SDL.h>
#include "SdlRectCollision.h"
#include "GameEntity.h"

class QuadTreeNode
{		
	private:
		std::vector<GameEntity*> nodeObjects;
		std::vector<QuadTreeNode*> nodeChildren;
		
	private:
		const int QuadTreeNodeCapacity=4;
        bool isNodeFull;
    
	private:	
		int nodeDepth;
		QuadTreeNode * parentNode;
		
	private:
		SDL_Rect * nodeBoundingBox;
		
		
	public:
		QuadTreeNode(const int depth = 0);
		
	public:	
		void Split();
		bool Insert(GameEntity*,int,bool forceIntoNode=false);
		bool Remove(GameEntity*);
		bool NodeCollision(const GameEntity*);
		bool ChildCollision(const GameEntity*);
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
		void DestroyAllChildren();
		void DestroyChild(QuadTreeNode*);
		void CreateNewChildren();
		SDL_Rect * GetChildBoundingBox(int);
		void MoveNodeObjectsToChildren(QuadTreeNode*);
		void MoveToChildIfCollisionOccurs(QuadTreeNode*,int);

};

#endif
