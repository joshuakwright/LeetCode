Initial Solution:

class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        emailSet = set()
        
        for email in emails:
            splitEmail = re.split("@", email)
            splitEmail[0] = re.sub("\+.*", "", splitEmail[0])
            splitEmail[0] = re.sub("\.", "", splitEmail[0])
            finalEmail = splitEmail[0] + "@" + splitEmail[1]
            emailSet.add(finalEmail)
        
        return len(emailSet)

Faster Solution:

class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        emailSet = set()
        for email in emails:
            local, domain = email.split('@')
            local = local.split('+')[0].replace('.', '')
            emailSet.add(local + "@" + domain)
            
        return len(emailSet)