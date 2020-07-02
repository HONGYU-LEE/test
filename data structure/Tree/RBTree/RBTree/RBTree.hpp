#pragma once
#include<iostream>

namespace lee
{
	enum Color
	{
		BLACK,
		RED,
	};

	//template<class K, class V>
	//struct KeyOfValue
	//{
	//	const K& operator()(const std::pair<K, V>& kv)
	//	{
	//		return kv.first;
	//	}
	//};

	template<class T>
	struct RBTreeNode
	{
		typedef RBTreeNode<T> Node;

		RBTreeNode(const T& data = T(), const Color& color = RED) 
			: _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _data(data)
			, _color(color)
		{}

		Node* _left;
		Node* _right;
		Node* _parent;
		T _data;
		Color _color;
	};

	template<class T, class Ptr, class Ref>
	struct __RBTreeIterator
	{
		typedef RBTreeNode<T> Node;
		typedef __RBTreeIterator<T, Ptr, Ref> Self;

		__RBTreeIterator(Node* node) : _node(node)
		{}

		Ref operator *()
		{
			return _node->_data;
		}

		//����ʱ��ʵ���õ���->->�����ﷵ�ص������ݶ����ָ�룬Ȼ���ٴ�ָ����ȡ���ݡ��������Ż�����ֻ����һ��
		Ptr operator ->()
		{
			return &_node->_data;
		}

		//�������������++ --��ʵ����������������еĴ���仯
		Self& operator++()
		{
			/*
				����������ȷ������нڵ�������������ŷ�����Щ�ڵ����������
				��++����ʵ�������������������һ��λ��
				1.�����ǰ�ڵ����������Ϊ�գ���˵����ǰ�ڵ����������û�����꣬��һ��λ������������������ڵ㡣

				2.�����ʱ������Ϊ�գ���˵����ǰ�ڵ���������������꣬���ǵ�ǰ�ڵ�Ҳ����Ϊ��������������������һֱ���ϣ��ҵ�����Ϊ���׵��������Ľ�㣬�Ǹ����׵�λ��������һ��λ��
			*/

			if (_node->_right)
			{
				Node* cur = _node->_right;

				//�ҵ�������������ڵ�
				while (cur && cur->_left)
				{
					cur = cur->_left;
				}

				_node = cur;
			}
			else
			{
				Node* parent = _node->_parent;
				Node* cur = _node;
				
				//�����ң�ֱ�����ڵ�Ϊ�ջ��ߺ��ӽڵ�Ϊ���ڵ��������
				while (parent->_left != cur)
				{
					cur = parent;
					parent = parent->_parent;
				}

				_node = parent;
			}
			
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			++(*this);

			return temp;
		}
		/*
				��--����ʵ�������������������һ��λ�ã�˼·��++���
				1.�����ǰ�ڵ����������Ϊ�գ�����������������ҽڵ�
				2.�����ʱ������Ϊ�գ���˵������������ڵ��Ѿ����ʣ����ž����ϲ��ң��ҵ�����Ϊ���׵��ҽڵ��λ�ã��Ǹ����׾�����һ��λ��
		*/
		Self& operator--()
		{
			if (_node->_parent->_parent == _node && _node->_color == RED)
			{
				//����˽ڵ�Ϊͷ��㣬��˵��--Ӧ�ûص�����������λ�ã�Ҳ����ͷ����������������Ϊͷ���͸��ڵ��γɱջ������Ե�
				//_node->_parent->_parent == _node������colorΪ��ʱ��˵��Ϊ_head��
				
				_node = _node->_right;
			}
			else if (_node->_left)
			{
				Node* cur = _node->_left;

				//�ҵ������������ҽڵ�
				while (cur && cur->_right)
				{
					cur = cur->_right;
				}

				_node = cur;
			}
			else
			{
				Node* parent = _node->_parent;
				Node* cur = _node;

				//�����ң�ֱ�����ڵ�Ϊ�ջ��ߺ��ӽڵ�Ϊ���ڵ��������
				while (parent->_right != cur)
				{
					cur = parent;
					parent = parent->_parent;
				}

				_node = parent;
			}
			return *this;
		}

		Self operator--(int)
		{
			Self temp(*this);
			--(*this);

			return temp;
		}
		bool operator==(const Self& s)
		{
			return _node == s._node;
		}

		bool operator!=(const Self& s)
		{
			return &_node != &s._node;
		}

		Node* _node;
	};

	template<class K, class T, class KOfV>
	class RBTree
	{
		typedef RBTreeNode<T> Node;
		typedef __RBTreeIterator<T, T*, T&> iterator;
		typedef __RBTreeIterator<T, const T*, const T&> const_iterator;

	public:
		RBTree() 
			: _root(nullptr)
			, _head(new Node(T(), RED))
		{
			_head->_left = _head;
			_head->_right = _head;
			_head->_parent = _head;
		}

		~RBTree()
		{
			destory(_head->_parent);
		}

		//ͷ��������������begin()
		iterator begin() 
		{
			return iterator(_head->_left);
		}

		//ͷ��㱾�����end()
		iterator end() 
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return iterator(_head->_left);
		}

		const_iterator end() const
		{
			return iterator(_head);
		}

		Node* leftMax()
		{
			Node* cur = _head->_parent;

			while (cur && cur->_left)
			{
				cur = cur->_left;
			}

			return cur;
		}

		Node* rightMax()
		{
			Node* cur = _head->_parent;

			while (cur && cur->_right)
			{
				cur = cur->_right;
			}

			return cur;
		}

		void _InOrderTravel(Node* root) const
		{
			if (root == nullptr)
				return;

			_InOrderTravel(root->_left);

			std::cout << root->_data.first << ':' << root->_data.second << std::endl;

			_InOrderTravel(root->_right);
		}

		void InOrderTravel() const
		{
			_InOrderTravel(_head->_parent);
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
			if (parent == _head->_parent)
			{
				_head->_parent = subL;
				subL->_parent = _head;
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

			if (parent == _head->_parent)
			{
				_head->_parent = subR;
				subR->_parent = _head;
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
		}

		iterator Find(const T& data)
		{
			//���ݶ��������������ʣ��Ӹ��ڵ�������ȸ��ڵ����������������ȸ��ڵ�С�����������
			Node* cur = _head->_parent;
			KOfV kofv;

			while (cur)
			{
				//�ȸ��ڵ�������������
				if (koft(data) > kofv(cur->_data))
				{
					cur = cur->_right;
				}
				//�ȸ��ڵ�С�����������
				else if (koft(data) < kofv(cur->_data))
				{
					cur = cur->_left;
				}
				//��ͬ�򷵻�
				else
				{
					return iterator(cur);
				}
			}

			//��������˵�����Ҳ���������false
			return iterator(_head);
		}

		std::pair<iterator, bool> Insert(const T& data)
		{
			KOfV kofv;

			//���ն����������Ĺ������ҵ�λ��
			if (_root == nullptr)
			{
				_root = new Node(data, BLACK);

				//�γɻ��νṹ
				_root->_parent = _head;

				_head->_left = _root;
				_head->_right = _root;
				_head->_parent = _root;

				return make_pair(iterator(_root), true);
			}

			Node* cur = _head->_parent;
			Node* parent = _head;

			while (cur)
			{
				if (kofv(data) > kofv(cur->_data))
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (kofv(data) < kofv(cur->_data))
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return make_pair(iterator(cur), false);
				}
			}

			//�²���ڵ�Ϊ��ɫ
			cur = new Node(data, RED);

			//�������Ľ�㣬��Ϊ��������ϸ��º����������cur���ܻ�仯��
			Node* newNode = cur;

			//�жϲ���λ��
			if (kofv(cur->_data) > kofv(parent->_data))
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}
			cur->_parent = parent;

			//���º������������ڵ����ɫΪ�ڣ���˵����������������Ҫ�������Ϊ�죬��˵�������㣬��Ҫ����
			while (cur != _head->_parent && parent && parent->_color == RED)
			{
				Node* ppNode = parent->_parent;

				//������ڵ�Ϊ�游��������
				if (ppNode->_left == parent)
				{
					//��ʱ�ж�����ڵ��״̬�������״̬ȡ��������
					Node* uncle = ppNode->_right;

					//��һ��������������ڵ������Ϊ�죬��ֱ�ӰѸ��׺������ڣ��游�ڵ�ߺ켴�ɡ�Ȼ���ٴ��游��λ�ü������ϵ���
					if (uncle && uncle->_color == RED)
					{
						//��ɫ
						uncle->_color = parent->_color = BLACK;
						ppNode->_color = RED;

						//��������
						cur = ppNode;
						parent = cur->_parent;
					}
					/*
						����ڵ�Ϊ�ڻ��߲����ڣ���ʱ���������
						�������curΪ���ڵ������������ֱ��״̬��
						�������curΪ���ڵ����������������״̬��

						���������һ�κ������ɫ�������
						���������������������һ����ת������΢�����Ϳ���ת���������
					 */
					else
					{
						//��Ϊ�����˫����AVL��һ�������Բ��ô���ƽ�����ӣ��������Ϊ����������ת����󣬽���ת��Ϊֱ�ߴ����ɡ�

						//���������������״̬��ת��Ϊֱ��״̬����
						if (parent->_right == cur)
						{
							RotateL(parent);
							//�������ٽ����ڵ㣬���ɱ��ֱ��״̬��
							std::swap(parent, cur);
						}

						//����ڶ���״̬
						RotateR(ppNode);

						parent->_color = BLACK;
						ppNode->_color = RED;

						//�������
						break;
					}

				}
				//�������Ϊ�游��������
				else
				{
					//��ʱ����Ϊ��������
					Node* uncle = ppNode->_left;

					if (uncle && uncle->_color == RED)
					{
						uncle->_color = parent->_color = BLACK;
						ppNode->_color = RED;

						cur = ppNode;
						parent = cur->_parent;
					}
					else
					{
						if (parent->_left == cur)
						{
							RotateR(parent);
							std::swap(cur, parent);
						}

						RotateL(ppNode);

						ppNode->_color = RED;
						parent->_color = BLACK;

						break;
					}
				}
			}

			//Ϊ�˷�ֹ��С�İѸ��ڵ��Ϊ��ɫ������ֶ���Ϊ��ɫ����
			_head->_parent->_color = BLACK;

			//��������ͷ����״̬��
			_head->_left = leftMax();
			_head->_right = rightMax();

			return make_pair(iterator(newNode), true);
		}

		/*
			�ж��Ƿ�Ϊ������������ж����Ƿ���������������

			���ԣ�	3.���ڵ����Ϊ�ڽڵ�
					1.�����������ĺ���
				    2.��ĳһ�ڵ�����������е�Ҷ�ӽڵ㣬���о����ĺ�ɫ�ڵ��������
				  
		*/
		bool IsRBTree()
		{
			if (_root == nullptr)
			{
				//����Ҳ�Ǻ����
				return true;
			}

			//Υ������1
			if (_root->_color != BLACK)
			{
				return false;
			}

			//��ȡ�Ӹ��ڵ����������һ����·���ĺ�ɫ�ڵ���������ѡȡ����������
			Node* cur = _root;
			size_t blackCount = 0;
			size_t count = 0;

			while (cur)
			{
				if (cur->_color == BLACK)
				{
					blackCount++;
				}

				cur = cur->_left;
			}

			//�ݹ��ж�����·���ĺ�ɫ�ڵ���
			return _IsRBTree(_root, count, blackCount);
		}

		bool _IsRBTree(Node* root, size_t count, const size_t blackCount)
		{
			//��ʱ˵���Ѿ��ߵ�Ҷ�ӽڵ㣬�жϺ�ɫ�ڵ����Ƿ���ȣ��������Υ������3
			if (root == nullptr)
			{
				if (count != blackCount)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			//���û���꣬�ͽ����ж��������

			//�ж�����2��������������ĺ��㣬�򷵻ش���
			Node* parent = root->_parent;

			if (parent && root->_color == RED && parent->_color == RED)
			{
				return false;
			}

			//�����ǰ�ڵ�Ϊ��ɫ�����¼
			if (root->_color == BLACK)
			{
				count++;
			}

			//���ŵݹ��жϵ�ǰ�ڵ������·��
			return _IsRBTree(root->_left, count, blackCount) && _IsRBTree(root->_right, count, blackCount);
		}
		
	private:
		Node* _root;
		//��װһ��ͷ��㣬ͷ���ĸ���ָ����ڵ㣬������ָ��begin()Ҳ��������ڵ㣬��������Ϊ���ҽڵ㣬��ô������������Ϊend(��Ҫ�������ҽڵ����һ���ڵ㡣
		//����ͷ���Ϊ��ɫ���������ָ��ڵ�
		Node* _head;
	};
}