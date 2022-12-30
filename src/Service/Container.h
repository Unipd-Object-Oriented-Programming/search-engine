#ifndef SERVICE_CONTAINER_H
#define SERVICE_CONTAINER_H

namespace Service {

template <typename T>
class Container {
  public:
    class Node {
      private:
        T data;
        Node* next;

      public:
        Node(T data, Node* next): data(data), next(next) {
        }

        T getData() const {
            return data;
        }

        Node& setData(T data) {
            this->data = data;
            return *this;
        }

        Node* getNext() const {
            return next;
        }

        Node& setNext(Node* next) {
            this->next = next;
            return *this;
        }
    };

  private:
    Node* head;

  public:
    Container(): head(nullptr) {
    }

    ~Container() {
        clear();
    }

    unsigned int getSize() const {
        unsigned int size = 0;
        Node* n = head;
        while (n != nullptr) {
            n = n->getNext();
            size++;
        }
        return size;
    }

    Node* getHead() const {
        return head;
    }

    Container& add(T data) {
        head = new Node(data, head);
        return *this;
    }

    Container& remove(T data) {
        Node* previous = nullptr;
        Node* current = head;
        while (current != nullptr) {
            if (current->getData() == data) {
                if (previous != nullptr) {
                    previous->setNext(current->getNext());
                }
                else {
                    head = current->getNext();
                }
                delete current;
                return *this;
            }
            previous = current;
            current = current->getNext();
        }
        return *this;
    }

    Container& clear() {
        while (head != nullptr) {
            Node* next = head->getNext();
            delete head;
            head = next;
        }
        return *this;
    }
};

}

#endif