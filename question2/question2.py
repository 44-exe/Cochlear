
from os import remove


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

    # method for printing list
    def print_list(self):
        print_node = self.head
        while print_node is not None:
            print(f"print_node.data: {print_node.data}")
            print_node = print_node.next



if __name__=="__main__":
    print("running main")
    ll = LinkedList()
    ll.insert_node(Node("Mon"))
    ll.insert_node(Node("Tue"))
    ll.insert_node(Node("Thu"))
    ll.print_list()

    ll.delete_node(Node("Thu"))
    print("Corrected")
    ll.insert_node(Node("Wed"))
    ll.insert_node(Node("Thu"))
    ll.print_list()

    print("")
    ll.total_nodes()



# End of File
