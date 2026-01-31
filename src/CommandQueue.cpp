#include "CommandQueue.hpp"

void CommandQueue::push(const Command& command) { m_queue.push(command); }

Command CommandQueue::pop() {
  Command first = m_queue.front();
  m_queue.pop();
  return first;
}

bool CommandQueue::isEmpty() const { return m_queue.empty(); }