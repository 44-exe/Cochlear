
class Node:
    def __init__(self, data_val=None):
        self.data = data_val
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    #method for inserting new nodes
    def insert_node(self, new_node):
        if self.head:
            last_node = self.head
            while last_node.next:
                last_node = last_node.next
            last_node.next = new_node
        else:
            self.head = new_node

    # method for deleting nodes
    def delete_node(self, remove_node):
        current_node = self.head

        if current_node:
            if current_node.data == remove_node.data:
                self.head = current_node.next
                current_node = None
                return
        while current_node:
            if current_node.data == remove_node.data:
                break
            prev_node = current_node
            current_node = current_node.next

        if current_node is None:
            return

        prev_node.next = current_node.next
        current_node = None

    # method for determining total nodes
    def total_nodes(self):
        current_node = self.head
        count = 0
        while current_node:
            current_node = current_node.next
            count += 1
        return count

    # method for printing list in forward order
    def print_list(self):
        print_node = self.head
        while print_node is not None:
            print(f"print forward: {print_node.data}")
            print_node = print_node.next

    # method for printing list in reverse order
    def print_list_reverse(self, current_node):
        if current_node is None:
            return
        self.print_list_reverse(current_node.next)
        print(f"print reverse: {current_node.data}")


if __name__=="__main__":
    print("running main")
    ll = LinkedList()
    ll.insert_node(Node(0))
    ll.insert_node(Node(1))
    ll.insert_node(Node(3))
    ll.insert_node(Node(4))
    ll.print_list()

    ll.delete_node(Node(3))
    ll.delete_node(Node(4))
    print("")
    print("Corrected by deleting 3 and 4")
    ll.insert_node(Node(2))
    ll.insert_node(Node(3))
    ll.insert_node(Node(4))
    ll.insert_node(Node(5))
    ll.insert_node(Node(6))
    ll.insert_node(Node(7))
    ll.insert_node(Node(8))
    ll.insert_node(Node(9))
    ll.print_list()

    print("")
    print(f"total node count: {ll.total_nodes()}")

    print("")
    ll.print_list_reverse(ll.head)


# End of File
