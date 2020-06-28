#pragma once
#include<iostream>

namespace lee
{
	template<class K, class V>
	struct AVLTreeNode
	{
		AVLTreeNode(const std::pair<K, V>& kv)
			: _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _kv(kv)
			, _bf(0)
		{}

		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		AVLTreeNode<K, V>* _parent;
		std::pair<K, V> _kv;
		int _bf;
	};

	template<class K, class V>
	class AVLTree
	{
	public:
		typedef AVLTreeNode<K, V> Node;

		AVLTree() : _root(nullptr)
		{}

		~AVLTree()
		{
			destory(_root);
		}

		//����
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;

			//���subLR���ڣ��������ĸ��ڵ�ָ��parent��
			if (subLR)
			{
				subLR->_parent = parent;
			}

			subL->_right = parent;

			Node* ppNode = parent->_parent;
			parent->_parent = subL;

			//�������
			//���parentΪ���ڵ㣬����subL��Ϊ�µĸ��ڵ�
			if (parent == _root)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			//������Ǹ��ڵ㣬��ı�subL�����游�ڵ��ָ���ϵ
			else
			{
				if (ppNode->_left == parent)
				{
					ppNode->_left = subL;
				}
				else
				{
					ppNode->_right = subL;
				}

				subL->_parent = ppNode;
			}

			//������ɺ�ƽ�⣬ƽ�����ӹ��㡣
			subL->_bf = parent->_bf = 0;
		}

		//����
		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			parent->_right = subRL;

			if (subRL)
			{
				subRL->_parent = parent;
			}

			subR->_left = parent;
			Node* ppNode = parent->_parent;
			parent->_parent = subR;

			if (parent == _root)
			{
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				if (ppNode->_left == parent)
				{
					ppNode->_left = subR;
				}
				else
				{
					ppNode->_right = subR;
				}

				subR->_parent = ppNode;
			}

			subR->_bf = parent->_bf = 0;
		}

		//����˫��
		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			//������Ҫ����subRL��ƽ�����ӣ���������ת����ƽ������
			int bf = subRL->_bf;

			//���ҵ��������߽ṹת��Ϊֱ�߽ṹ��Ҳ����ǰ�浥���Ϳ��Խ�������⡣
			RotateR(subR);
			//Ȼ������������
			RotateL(parent);

			//����subRL��bf��������ת���ƽ������
			if (bf == 1)
			{
				parent->_bf = -1;
				subR->_bf = 0;
				subRL->_bf = 0;
			}
			else if (bf == -1)
			{
				parent->_bf = 0;
				subR->_bf = 1;
				subRL->_bf = 0;
			}
			else
			{
				parent->_bf = 0;
				subR->_bf = 0;
				subRL->_bf = 0;
			}
		}


		//����˫��
		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			int bf = subLR->_bf;

			RotateL(subL);
			RotateR(parent);

			if (bf == 1)
			{
				parent->_bf = 0;
				subL->_bf = -1;
				subLR->_bf = 0;
			}
			else if (bf == -1)
			{
				parent->_bf = 1;
				subL->_bf = 0;
				subLR->_bf = 0;
			}
			else
			{
				parent->_bf = 0;
				subL->_bf = 0;
				subLR->_bf = 0;
			}
		}

		bool Insert(const std::pair<K, V>& kv)
		{
			//���ն����������Ĺ������ҵ�λ��
			if (_root == nullptr)
			{
				_root = new Node(kv);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (kv.first > cur->_kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (kv.first < cur->_kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			//����ڵ�
			cur = new Node(kv);

			//�жϲ���λ��
			if (cur->_kv.first > parent->_kv.first)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			cur->_parent = parent;

			//����ƽ������
			while (parent)
			{
				//���¸��ڵ��ƽ������
				if (cur == parent->_left)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}

				//�жϸ��º󸸽ڵ��Ƿ�ƽ��
				
				//ƽ��
				if (parent->_bf == 0)
				{
					break;
				}
				//�߶ȷ����仯��Ҫ���������ж�
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				//��ʱ��ƽ�⣬��Ҫ��ת
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					//��ת�����������ֱ�ߵ���������˫��

					if (parent->_bf == 2)
					{
						//����ұ߲�ƽ�⣬�����ӽڵ�Ҳ���ұ�ƫ�أ�������
						if (cur->_bf == 1)
						{
							RotateL(parent);
						}
						//����ұ߲�ƽ�⣬���ӽڵ������ƫ�أ���ʱ��Ҫ��ת��Ϊ�����״̬�����ҵ��������������ǲ���ֱ���ҵ���������������Ҫ�����������ƽ������
						else
						{
							RotateRL(parent);
						}
					}
					else
					{
						//��߲�ƽ�⣬�����ӽڵ�Ҳ�����ƫ�أ��ҵ���
						if (cur->_bf == -1)
						{
							RotateR(parent);
						}
						//ͬ�ϣ�����˫��
						else
						{
							RotateLR(parent);
						}
					}

					//��ת���ָ�ƽ�⣬���½�����
					break;
				}
			}

			return true;
		}

		Node* Find(const K& key)
		{
			//���ݶ��������������ʣ��Ӹ��ڵ�������ȸ��ڵ����������������ȸ��ڵ�С�����������
			Node* cur = _root;

			while (cur)
			{
				//�ȸ��ڵ�������������
				if (key > cur->_kv.first)
				{
					cur = cur->_right;
				}
				//�ȸ��ڵ�С�����������
				else if (key < cur->_kv.first)
				{
					cur = cur->_left;
				}
				//��ͬ�򷵻�
				else
				{
					return cur;
				}
			}

			//��������˵�����Ҳ���������false
			return nullptr;
		}

		bool erase(const K& key)
		{
			//ɾ��ֱ�Ӱ��ն����������Ĺ���ɾ����Ȼ���ٽ���ƽ�����ӵĸ��¼���
			Node* cur = _root;
			Node* parent = cur;

			
			/*
				ɾ�������������һ����ɾ��Ҷ�ӽڵ㣬����ֱ��ɾ��
				�ڶ�����������ɾ���Ľڵ�ֻ��һ����������ôɾ������ڵ�󣬾��ø��ڵ�ָ��������һ����
				ǰ����������Ժϲ�����

				�������������������������Ϊ�գ���ʱѡ��һ�����ڵ����滻������ɾ�����Ϳ��Բ��ƻ�ԭ�нṹ
				���Ҫ����ԭ�нṹ���仯����ôѡ��Ľڵ����Ҫ��ɾ���ڵ�������������������ģ��������ֻ�������ڵ㣬һ�����������������ֵ��һ����������������Сֵ��
			*/
			//ɾ������
			while (cur)
			{
				//�ҵ�ɾ����λ��
				if (key > cur->_kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					//ǰ��������ϲ����������ǰ���ֻ��һ�����������ø��ڵ�ָ����������
					//����ֻ��������ʱ					
					if (cur->_left == nullptr)
					{
						//�����ǰ�ڵ�Ϊ���ڵ㣬������������Ϊ�µĸ��ڵ�
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							//�жϵ�ǰ�ڵ��������ڵ����һ������
							if (parent->_right == cur)
							{
								parent->_right = cur->_right;
							}
							else
							{
								parent->_left = cur->_right;
							}
						}

						delete cur;
					}
					//����ֻ��������ʱ	
					else if (cur->_right == nullptr)
					{
						//�����ǰ�ڵ�Ϊ���ڵ㣬������������Ϊ�µĸ��ڵ�
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_right == cur)
							{
								parent->_right = cur->_left;
							}
							else
							{
								parent->_left = cur->_left;
							}
						}

						delete cur;
					}
					//����������������Ϊ��ʱ,ѡȡ�����������ҽڵ����������������ڵ�
					else
					{
						//������ѡȡ���������������ҽڵ�

						Node* LeftMax = cur->_left;
						Node* LeftMaxParent = cur;

						//�ҵ������������ҽڵ�
						while (LeftMax->_right)
						{
							LeftMaxParent = LeftMax;
							LeftMax = LeftMax->_right;
						}

						//�滻�ڵ�
						cur->_kv.first = LeftMax->_kv.first;

						//�жϵ�ǰ�ڵ��������ڵ����һ������, ��Ϊ�Ѿ������������ˣ���������ڵ��������Ϊ�գ��������������ܻ������ݣ������ø��ڵ�ָ������������
						//����ɾ�����ҽڵ�
						if (LeftMax == LeftMaxParent->_left)
						{
							LeftMaxParent->_left = LeftMax->_left;
						}
						else
						{
							LeftMaxParent->_right = LeftMax->_left;
						}

						delete LeftMax;
					}

					//ɾ���ɹ����ж�
					break;
				}
			}

			//���Ҳ���
			if (cur == nullptr)
				return false;

			//����ƽ������
			while (parent)
			{
				//���¸��ڵ��ƽ������
				if (cur == parent->_left)
				{
					parent->_bf++;
				}
				else
				{
					parent->_bf--;
				}

				//�жϸ��º󸸽ڵ��Ƿ�ƽ��

				//ƽ��
				if (parent->_bf == 0)
				{
					break;
				}
				//�߶ȷ����仯��Ҫ���������ж�
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				//��ʱ��ƽ�⣬��Ҫ��ת
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					//��ת�����������ֱ�ߵ���������˫��

					if (parent->_bf == 2)
					{
						//����ұ߲�ƽ�⣬�����ӽڵ�Ҳ���ұ�ƫ�أ�������
						if (cur->_bf == 1)
						{
							RotateL(parent);
						}
						//����ұ߲�ƽ�⣬���ӽڵ������ƫ�أ���ʱ��Ҫ��ת��Ϊ�����״̬�����ҵ��������������ǲ���ֱ���ҵ���������������Ҫ�����������ƽ������
						else
						{
							RotateRL(parent);
						}
					}
					else
					{
						//��߲�ƽ�⣬�����ӽڵ�Ҳ�����ƫ�أ��ҵ���
						if (cur->_bf == -1)
						{
							RotateR(parent);
						}
						//ͬ�ϣ�����˫��
						else
						{
							RotateLR(parent);
						}
					}

					//��ת���ָ�ƽ�⣬���½�����
					break;
				}
			}

			return true;
		}

		void _InOrderTravel(Node* root) const
		{
			if (root == nullptr)
				return;

			_InOrderTravel(root->_left);

			std::cout << root->_kv.first << ':'  << root->_kv.second << std::endl;

			_InOrderTravel(root->_right);
		}

		void InOrderTravel() const
		{
			_InOrderTravel(_root);
		}

		int countHeight(Node* root) const
		{
			if (root == nullptr)
				return 0;

			int leftHeight = countHeight(root->_left);
			int rightHeight = countHeight(root->_right);

			return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		}

		bool _IsBalance(Node* root) const
		{
			if (root == nullptr)
				return true;

			int leftHeight = countHeight(root->_left);
			int rightHeight = countHeight(root->_right);

			return abs(leftHeight - rightHeight) < 2
				&& _IsBalance(root->_left)
				&& _IsBalance(root->_right);
		}

		bool IsBalance() const
		{
			return _IsBalance(_root);
		}

		void destory(Node*& root)
		{
			Node* node = root;
			if (!root)
				return;

			destory(node->_left);
			destory(node->_right);

			delete node;
			node = nullptr;
		}
	private:
		Node* _root;
	};
};